#include "main.h"

/**
 * bfree - frees a pointer and nullify the address
 * @ptr: address of the pointer parameters
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

