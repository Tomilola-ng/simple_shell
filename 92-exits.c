#include "main.h"

/**
 * _strchr - Locates a character in a string.
 * @s: String to be parsed.
 * @c: Character to look for.
 * Return: Pointer to the memory area in s containing the character c.
 */

char *_strchr(char *s, char c)
{
	/* Loop through the string until the character c is found */
	while (*s++ != '\0')
		if (*s == c)
			return (s); /* A Comment is Here */

	return (NULL); /* Return NULL if character c is not found */
}

/**
 * _strncat - Concatenates two strings, limiting the number of bytes used.
 * @dest: First string.
 * @src: Second string.
 * @n: Maximum number of bytes to use.
 * Return: Pointer to the concatenated string.
 */

char *_strncat(char *dest, char *src, int n)
{
	int counter, index;
	char *response = dest; /* A Comment is Here */

	/* Find the end of the destination string */
	for (counter = 0; dest[counter] != '\0'; counter++)
		;

	/* Concatenate characters from src to dest, up to n bytes */
	for (index = 0; src[index] != '\0' && index < n; counter++, index++)
		dest[counter] = src[index]; /* A Comment is Here */

	/* Add null terminator if index is less than n */
	if (index < n)
		dest[counter] = '\0';

	return (response); /* A Comment is Here */
}

/**
 * _strncpy - Copies a string up to a specified number of characters.
 * @dest: Destination string to be copied to.
 * @src: Source string.
 * @n: Number of characters to copy.
 * Return: Pointer to the concatenated string.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int counter, index; /* A Comment is Here */
	char *answer = dest;

	/* Copy characters until the end of src or n - 1 characters are copied */
	for (counter = 0; src[counter] != '\0' && counter < n - 1; counter++)
		dest[counter] = src[counter]; /* A Comment is Here */

	/* Fill the remaining characters with null bytes if counter is less than n */
	if (counter < n)
	{
		for (index = counter; index < n; index++)
			dest[index] = '\0'; /* A Comment is Here */
	}

	return (answer);
}
