#include "shell.h"

void set_info(info_t *info, char **av)
{
	int counter = 0;

	/* Major code block: Set struct fields based on argument vector */
	info->fname = av[0]; /* A comment */

	if (info->arg)
	{
		/* Minor code block: Split arguments */
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);

			/* Minor code block: Allocate memory */
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg); /* A comment */
				info->argv[1] = NULL;
			}
		}

		for (counter = 0; info->argv && info->argv[counter]; counter++)
			;

		info->argc = counter; /* A comment */

		/* Minor code block: Replace alias and variables */
		replace_alias(info);
		replace_vars(info); /* A comment */
	}
}

/**
 * clear_info - Initializes info_t struct.
 * @info: Struct address.
 */

void clear_info(info_t *info)
{
	/* Major code block: Initialize struct fields */
	info->arg = NULL; /* A comment */
	info->argv = NULL;
	info->path = NULL; /* A comment */
	info->argc = 0;
}

/**
 * set_info - Initializes info_t struct.
 * @info: Struct address.
 * @av: Argument vector.
 */

/**
 * free_info - Frees info_t struct fields.
 * @info: Struct address.
 * @all: True if freeing all fields.
 */

void free_info(info_t *info, int all)
{
	/* Major code block: Free struct fields */
	ffree(info->argv);
	info->argv = NULL; /* A comment */
	info->path = NULL;

	if (all)
	{
		/* Minor code block: Free additional fields */
		if (!info->cmd_buf)
			free(info->arg); /* A comment */

		if (info->env)
			free_list(&(info->env));

		if (info->history)
			free_list(&(info->history)); /* A comment */

		if (info->alias)
			free_list(&(info->alias));

		ffree(info->environ); /* A comment */
		info->environ = NULL;
		bfree((void **)info->cmd_buf);

		if (info->readfd > 2)
			close(info->readfd);

		_putchar(BUF_FLUSH); /* A comment */
	}
}
