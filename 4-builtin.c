#include "shell.h"

/**
 * print_alias - Print an alias string.
 * @node: The alias node.
 * Return: Always 0 on success, 1 on error.
 */

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '='); /* A Comment here */
		for (a = node->str; a <= p; a++)
			_putchar(*a);

		_putchar('\''); /* A Comment here */
		_puts(p + 1);
		_puts("'\n"); /* A Comment here */
		return (0);
	}

	return (1);
}

/**
 * unset_alias - Unset alias to a string.
 * @info: Parameter struct.
 * @str: The string alias.
 * Return: Always 0 on success, 1 on error.
 */

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret; /* A Comment here */

	p = _strchr(str, '=');
	if (!p)
		return (1); /* A Comment here */

	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
							   get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c; /* A Comment here */
	return (ret);
}

/**
 * _myhistory - Display the history list, showing each command with line
 *               numbers starting at 0.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */

int _myhistory(info_t *info)
{
	/* Print the history list */
	print_list(info->history);
	return (0); /* A Comment here */
}

/**
 * set_alias - Set alias to a string.
 * @info: Parameter struct.
 * @str: The string alias.
 * Return: Always 0 on success, 1 on error.
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1); /* A Comment here */

	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str); /* A Comment here */
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
