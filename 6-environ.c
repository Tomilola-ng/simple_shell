#include "shell.h"

/**
 * populate_env_list - Populates the environment linked list.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL; /* A Comment Here */
	size_t i;

	/* Populate the environment list from the 'environ' global variable */
	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0); /* A Comment Here */

	/* Set the 'env' member of the 'info' structure to the populated list */
	info->env = node;
	return (0);
}

/**
 * _getenv - Gets the value of an environment variable.
 * @info: Structure containing potential arguments.
 * @name: Environment variable name.
 * Return: The value of the environment variable.
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env; /* A Comment Here */
	char *p;

	/* Iterate through the environment list to find the variable */
	while (node)
	{
		p = starts_with(node->str, name); /* A Comment Here */
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL); /* A Comment Here */
}

/**
 * _mysetenv - Inits a new environment variable or modifies an existing one.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */

int _mysetenv(info_t *info)
{
	/* Check for the correct number of arguments */
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n"); /* A Comment Here */
		return (1);
	}

	/* Set the environment variable */
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1); /* A Comment Here */
}

/**
 * _myenv - Prints the current environment.
 * @info: Structure containing potential arguments.
 *        Used to maintain constant function prototype.
 * Return: Always 0
 */

int _myenv(info_t *info)
{
	/* Print the environment list */
	print_list_str(info->env); /* A Comment Here */
	return (0);
}

/**
 * _myunsetenv - Removes an environment variable.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */

int _myunsetenv(info_t *info)
{
	int i;

	/* Check for the minimum number of arguments */
	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n"); /* A Comment Here */
		return (1);
	}

	/* Unset each specified environment variable */
	for (i = 1; i < info->argc; i++)
		_unsetenv(info, info->argv[i]); /* A Comment Here */

	return (0);
}
