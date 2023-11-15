#include "shell.h"

/**
 * _putfd - Writes a character to the given file descriptor.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putfd(char c, int fd)
{
	/* Static variables to manage buffering and flushing */
	static int i;
	static char buf[WRITE_BUF_SIZE]; /* A Comment Here */

	/* Flush the buffer if a flush character is encountered or buffer is full */
	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i); /* A Comment Here */
		i = 0;
	}

	/* If not a flush character, add the character to the buffer */
	if (c != BUF_FLUSH)
		buf[i++] = c; /* A Comment Here */

	return (1);
}

/**
 * _eputs - Prints a string to the standard error.
 * @str: The string to be printed.
 * Return: Nothing.
 */

void _eputs(char *str)
{
	/* Iterate through the string and print each character to stderr */
	int i = 0;

	if (!str)
	{
		return; /* A Comment Here */
	}

	while (str[i] != '\0')
	{
		_eputchar(str[i]); /* A Comment Here */
		i++;
	}
}

/**
 * _eputchar - Writes a character to the standard error.
 * @c: The character to print.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _eputchar(char c)
{
	/* Static variables to manage buffering and flushing */
	static int i;
	static char buf[WRITE_BUF_SIZE]; /* A Comment Here */

	/* Flush the buffer if a flush character is encountered or buffer is full */
	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i); /* A Comment Here */
		i = 0;
	}

	/* If not a flush character, add the character to the buffer */
	if (c != BUF_FLUSH)
		buf[i++] = c; /* A Comment Here */

	return (1);
}

/**
 * _putsfd - Prints a string to the specified file descriptor.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 * Return: The number of characters written.
 */

int _putsfd(char *str, int fd)
{
	/* Iterate through the string and print each character to the specified file descriptor */
	int i = 0; /* A Comment Here */

	if (!str)
		return (0); /* A Comment Here */

	while (*str)
	{
		i += _putfd(*str++, fd); /* A Comment Here */
	}

	return (i); /* A Comment Here */
}
