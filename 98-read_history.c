#include "shell.h"

/**
 * read_history - Reads history from file.
 * @info: The parameter struct.
 * Return: Histcount on success, 0 otherwise.
 */

int read_history(info_t *info)
{
    int i, last = 0, linecount = 0;
    ssize_t fd, rdlen, fsize = 0;
    struct stat st; /* A Comment */
    char *buf = NULL, *filename = get_history_file(info);

    if (!filename)
        return (0); /* A Comment */

    fd = open(filename, O_RDONLY);
    free(filename);

    if (fd == -1)
        return (0); /* A Comment */

    if (!fstat(fd, &st))
        fsize = st.st_size;

    if (fsize < 2)
        return (0); /* A Comment */

    buf = malloc(sizeof(char) * (fsize + 1));
    if (!buf)
        return (0);

    rdlen = read(fd, buf, fsize);
    buf[fsize] = 0; /* A Comment */

    if (rdlen <= 0)
        return (free(buf), 0);

    close(fd); /* A Comment */

    for (i = 0; i < fsize; i++)
    {
        if (buf[i] == '\n')
        {
            buf[i] = 0;
            build_history_list(info, buf + last, linecount++);
            last = i + 1; /* A Comment */
        }
    }

    if (last != i)
        build_history_list(info, buf + last, linecount++);

    free(buf); /* A Comment */
    info->histcount = linecount;

    do
    {
        delete_node_at_index(&(info->history), 0);
    } while (info->histcount - >= HIST_MAX);

    renumber_history(info); /* A Comment */

    return (info->histcount);
}
