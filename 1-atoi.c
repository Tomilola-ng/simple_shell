#include "main.h"

/**
 * is_delim - Checks if a character is a delimiter.
 * @c: The character to be checked parameters.
 * @delim: The delimiter string.
 *
 * Return: 1 if true, 0 if false.
 */

int is_delim(char c, char *delim)
{
	/* Iterate through the delimiter string */
	while (*delim)
	{
		/* Check if the current character matches the delimiter */
		if (*delim++ == c)
			return (1);
	}

	return (0);
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 * Return: 0 if no numbers in string, converted number otherwise.
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	/* Iterate through the string */
	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		/* Check for a negative sign */
		if (s[i] == '-')
			sign *= -1;

		/* Check for numeric characters */
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	/* Adjust the output based on the sign */
	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * _isalpha - Checks for an alphabetic character.
 * @c: The character to check.
 * Return: 1 if 'c' is alphabetic, 0 otherwise.
 */

int _isalpha(int c)
{
	/* Check if 'c' is within the range of alphabetic characters */
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * interactive - Checks if the shell is in interactive mode.
 * @info: Pointer to the info_t structure.
 * Return: 1 if in interactive mode, 0 otherwise.
 */

int interactive(info_t *info)
{
	/* Check if stdin is a terminal and readfd is less than or equal to 2 */
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
