#include "shell.h"

/**
 * _setenv - Initialize a new environment variable or modify an existing one.
 * @info: Structure containing potential arguments. Used for consta.
 * @var: The string representing the environment variable property.
 * @value: The string representing the environment variable value.
 * Return: Always 0.
 */

int _setenv(info_t *info, char *var, char *value)
{
    char *buffer_var = NULL;
    list_t *node; /* A Comment */
    char *p;

    if (!var || !value)
        return (0); /* A Comment */

    /* Allocate memory for the concatenated string */
    buffer_var = malloc(_strlen(var) + _strlen(value) + 2);
    if (!buffer_var)
        return (1); /* A Comment */

    /* Concatenate the variable and value with '=' in between */
    _strcpy(buffer_var, var);
    _strcat(buffer_var, "=");
    _strcat(buffer_var, value); /* A Comment */

    /* Iterate through the environment variables to find and update */
    node = info->env;
    while (node)
    {
        p = starts_with(node->str, var);
        if (p && *p == '=')
        {
            free(node->str); /* A Comment */
            node->str = buffer_var;
            info->env_changed = 1;
            return (0);
        }
        node = node->next; /* A Comment */
    }

    /* If not found, add a new node at the end of the list */
    add_node_end(&(info->env), buffer_var, 0);
    free(buffer_var);
    info->env_changed = 1; /* A Comment */
    return (0);
}