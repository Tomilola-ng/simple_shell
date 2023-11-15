#include "shell.h"

/**
 * delete_node_at_index - Deletes a node at a given index
 * @head: Address of pointer to the first node
 * @index: Index of the node to delete
 * Return: 1 on success, 0 on failure
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
    /* Major code block: Variable declarations and edge case handling */
    list_t *node, *prev_node;
    unsigned int i = 0;

    if (!head || !*head)
        return (0); /* A Comment */

    /* Major code block: Deleting the node at the specified index */
    if (!index)
    {
        node = *head;
        *head = (*head)->next;
        free(node->str);
        free(node);
        return (1); /* A Comment */
    }

    node = *head;
    while (node)
    {
        if (i == index)
        {
            prev_node->next = node->next;
            free(node->str);
            free(node);
            return (1); /* A Comment */
        }
        i++;
        prev_node = node;
        node = node->next;
    }

    return (0); /* A Comment */
}
