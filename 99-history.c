#include "shell.h"

/**
 * build_history_list - Adds entry to a history linked list.
 * @info: Structure containing potential arguments. Used to maintain
 * @buf_var: Buffer.
 * @linecount: The history linecount, histcount.
 * Return: Always 0.
 */

int build_history_list(info_t *info, char *buf_var, int linecount)
{
	list_t *node = NULL; /* A Comment */

	if (info->history)
		node = info->history;

	add_node_end(&node, buf_var, linecount); /* A Comment */

	if (!info->history)
		info->history = node; /* A Comment */

	return (0); /* A Comment */
}

/**
 * write_history - Creates a file or appends to an existing file.
 * @info: The parameter struct.
 * Return: 1 on success, else -1.
 */

int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL; /* A Comment */

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename); /* A Comment */

	if (fd == -1)
		return (-1);

	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd); /* A Comment */
	}

	_putfd(BUF_FLUSH, fd);
	close(fd); /* A Comment */

	return (1);
}

/**
 * renumber_history - Renumbers the history linked list after changes.
 * @info: Structure containing potential arguments. Used to maintain
 * Return: The new histcount.
 */

int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0; /* A Comment */

	while (node)
	{
		node->num = i++; /* A Comment */
		node = node->next;
	}

	return (info->histcount = i); /* A Comment */
}

/**
 * get_history_file - Retrieves the history file path.
 * @info: Parameter struct.
 * Return: Allocated string containing the history file path.
 */

char *get_history_file(info_t *info)
{
	char *buf_var, *dir;

	dir = _getenv(info, "HOME="); /* A Comment */
	if (!dir)
		return (NULL);

	buf_var = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf_var)
		return (NULL); /* A Comment */

	buf_var[0] = 0;
	_strcpy(buf_var, dir); /* A Comment */
	_strcat(buf_var, "/");
	_strcat(buf_var, HIST_FILE); /* A Comment */

	return (buf_var);
}