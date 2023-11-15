#include "shell.h"

/**
 * _myalias - Mimics the alias builtin (see 'man alias').
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */

int _myalias(info_t *info)
{
    int i = 0;
    char *equals_pos = NULL;      /* Position of '=' in an alias definition */
    list_t *current_alias = NULL; /* Pointer to the current alias node */

    /* Display all aliases if no specific alias is provided */
    if (info->argc == 1)
    {
        current_alias = info->alias;
        while (current_alias)
        {
            print_alias(current_alias);
            current_alias = current_alias->next; /* Move to the next alias node */
        }
        return (0);
    }

    /* Handle alias setting and printing */
    for (i = 1; info->argv[i]; i++)
    {
        equals_pos = _strchr(info->argv[i], '=');

        /* If '=' is present, set the alias */
        if (equals_pos)
            set_alias(info, info->argv[i]);
        else
            print_alias(node_starts_with(info->alias, info->argv[i], '='));
    }

    return (0);
}
