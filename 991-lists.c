#include "main.h"

/**
 * add_node - Adds a node to the start of the list
 * @head: Address of pointer to head node
 * @str: Str field of the node
 * @num: Node index used by history
 * Return: Size of the list
 */

list_t *add_node(list_t **head, const char *str, int num)
{
	/* Major code block: Variable declarations and memory allocation */
	list_t *new_head; /* A Comment */

	if (!head)
		return (NULL); /* A Comment */

	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL); /* A Comment */

	/* Major code block: Memory initialization and assignment */
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num; /* A Comment */

	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head); /* A Comment */
			return (NULL);
		}
	}

	/* Major code block: Node insertion at the beginning of the list */
	new_head->next = *head;
	*head = new_head;

	return (new_head); /* A Comment */
}

/**
 * add_node_end - Adds a node to the end of the list
 * @head: Address of pointer to head node
 * @str: Str field of the node
 * @num: Node index used by history
 * Return: Size of the list
 */

list_t *add_node_end(list_t **head, const char *str, int num)
{
	/* Major code block: Variable declarations and memory allocation */
	list_t *new_node, *node;

	if (!head)
		return (NULL); /* A Comment */

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL); /* A Comment */

	/* Major code block: Memory initialization and assignment */
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;

	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node); /* A Comment */
			return (NULL);
		}
	}

	/* Major code block: Node insertion at the end of the list */
	if (node)
	{
		do
		{
			node = node->next; /* A Comment */
		} while (node->next);

		node->next = new_node; /* A Comment */
	}
	else
		*head = new_node;

	return (new_node); /* A Comment */
}

/**
 * print_list_str - Prints only the str element of a list_t linked list
 * @h: Pointer to the first node
 * Return: Size of the list
 */

size_t print_list_str(const list_t *h)
{
	/* Major code block: Printing the str element of each node in the list */
	size_t i = 0; /* A Comment */

	while (h)
	{
		_puts(h->str ? h->str : "(nil)"); /* A Comment */
		_puts("\n");
		h = h->next; /* A Comment */
		i++;
	}

	return (i);
}

/**
 * free_list - Frees all nodes of a list
 * @head_ptr: Address of pointer to the head node
 * Return: void
 */

void free_list(list_t **head_ptr)
{
	/* Major code block: Freeing all nodes in the list */
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return; /* A Comment */

	head = *head_ptr;
	node = head;

	while (node)
	{
		next_node = node->next; /* A Comment */
		free(node->str);
		free(node);
		node = next_node; /* A Comment */
	}

	*head_ptr = NULL;
}
