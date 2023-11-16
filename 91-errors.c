#include "main.h"

/**
 * print_error - Prints an error message.
 * @info: The parameter & return info struct.
 * @estr: String containing specified error type.
 * Return: 0 if no numbers in string, converted number otherwise,
 * -1 on error.
 */

void print_error(info_t *info, char *estr)
{
	/* Print error information */
	_eputs(info->fname);
	_eputs(": "); /* A Cmment lives here*/
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": "); /* A Cmment lives here*/
	_eputs(info->argv[0]);
	_eputs(": "); /* A Cmment lives here*/
	_eputs(estr);
}

/**
 * remove_comments - Replaces the first instance of '#' with '\0'.
 * @buf: Address of the string to modify.
 * Return: Always 0.
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0'; /* A Cmment lives here*/
			break;
		}
}

/**
 * _erratoi - Converts a string to an integer.
 * @s: The string to be converted.
 * Return: 0 if no numbers in string, converted number otherwise,
 * -1 on error.
 */

int _erratoi(char *s)
{
	int i = 0; /* A Cmment lives here*/
	unsigned long int result = 0;

	if (*s == '+')
		s++; /* TODO: Investigate why this makes main return 255? */

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10; /* A Cmment lives here*/
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1); /* A Cmment lives here*/
		}
		else
			return (-1); /* A Cmment lives here*/
	}

	return (result);
}