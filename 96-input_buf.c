#include "shell.h"

/**
 * input_buf - Reads and buffers chained commands.
 * @info: Parameter struct.
 * @buf: Address of buffer.
 * @len: Address of len var.
 * Return: Bytes read.
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
    ssize_t r = 0; /* A Comment*/
    size_t len_p = 0;

    if (!*len)
    {
        free(*buf); /* Free the existing buffer */
        *buf = NULL;
        signal(SIGINT, sigintHandler); /* A Comment*/

#if USE_GETLINE
        r = getline(buf, &len_p, stdin); /* A Comment*/
#else
        r = _getline(info, buf, &len_p); /* A Comment*/
#endif

        if (r > 0)
        {
            if ((*buf)[r - 1] == '\n')
            {
                (*buf)[r - 1] = '\0'; /* Remove trailing newline */
                r--;                  /* A Comment*/
            }

            info->linecount_flag = 1;
            remove_comments(*buf); /* A Comment*/
            build_history_list(info, *buf, info->histcount++);

            /* Check if it's a command chain */
            if (_strchr(*buf, ';'))
            {
                *len = r;
                info->cmd_buf = buf; /* A Comment*/
            }
        }
    }
    return (r);
}
