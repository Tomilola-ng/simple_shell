#include "main.h"

/**
 * sigintHandler - Blocks ctrl-C.
 * @sig_num: The signal number.
 * Return: void.
 */

void sigintHandler(__attribute__((unused)) int sig_num)
{
	_puts("\n"); /* A Comment*/
	_puts("$ ");
	_putchar(BUF_FLUSH); /* A Comment*/
}

/**
 * get_input - Gets a line minus the newline.
 * @info: Parameter struct.
 * Return: Bytes read.
 */

ssize_t get_input(info_t *info)
{
	static char *buf; /* The ';' command chain buffer */
	static size_t counter, j, len;
	ssize_t r = 0; /* A Comment*/
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len); /* A Comment*/

	if (r == -1)
		return (-1);

	if (len)
	{
		j = counter;
		p = buf + counter; /* A Comment*/

		check_chain(info, buf, &j, counter, len);

		do
		{
			if (is_chain(info, buf, &j))
				break;
			j++;		   /* A Comment*/
		} while (j < len); /* A Comment*/

		counter = j + 1;

		if (counter >= len)
		{
			counter = len = 0;			   /* A Comment*/
			info->cmd_buf_type = CMD_NORM; /* A Comment*/
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf; /* A Comment*/
	return (r);
}

/**
 * _getline - Gets the next line of input from STDIN.
 * @info: Parameter struct.
 * @ptr: Address of pointer to buffer, preallocated or NULL.
 * @length: Size of preallocated ptr buffer if not NULL.
 * Return: s.
 */

int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE]; /* A Comment*/
	static size_t counter, len;
	size_t k; /* A Comment*/
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c; /* A Comment*/

	p = *ptr;

	if (p && length)
		s = *length; /* A Comment*/

	if (counter == len)
		counter = len = 0;

	r = read_buf(info, buf, &len);

	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + counter, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len; /* A Comment*/

	new_p = _realloc(p, s, s ? s + k : k + 1); /* A Comment*/

	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + counter, k - counter); /* A Comment*/
	else
		_strncpy(new_p, buf + counter, k - counter + 1); /* A Comment*/

	s += k - counter;
	counter = k; /* A Comment*/
	p = new_p;

	if (length)
		*length = s;

	*ptr = p; /* A Comment*/
	return (s);
}

/**
 * read_buf - Reads a buffer.
 * @info: Parameter struct.
 * @buf: Buffer.
 * @counter: Size.
 * Return: r.
 */

ssize_t read_buf(info_t *info, char *buf, size_t *counter)
{
	ssize_t r = 0;

	if (*counter)
		return (0);

	r = read(info->readfd, buf, READ_BUF_SIZE); /* A Comment*/

	if (r >= 0)
		*counter = r;

	return (r); /* A Comment*/
}
