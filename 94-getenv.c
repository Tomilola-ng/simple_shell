#include "shell.h"

/**
 * _unsetenv - Remove an environment variable.
 * @info: Structure containing potential arguments. Used.
 * @var: The string representing the environment variable property.
 * Return: 1 on successful deletion, 0 otherwise.
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p; /* A Comment */

	if (!node || !var)
		return (0); /* A Comment */

	while (node)
	{
		/* Check if the variable starts with the specified string */
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++; /* A Comment */
	}
	return (info->env_changed);
}

/**
 * get_environ - Retrieve the string array copy of the environment.
 * @info: Structure containing potential arguments. Used for constan.
 * Return: The string array representing the environment variables.
 */

char **get_environ(info_t *info)
{
	/* If environ is not initialized or has changed, update it */
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0; /* A Comment */
	}

	return (info->environ); /* A Comment */
}