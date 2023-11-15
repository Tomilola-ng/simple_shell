#include "shell.h"

/**
 * print_d - Prints a decimal (integer) number (base 10).
 * @input: The input.
 * @fd: The file descriptor to write to.
 * Return: Number of characters printed.
 */

int print_d(int input, int fd)
{
    int (*__putchar)(char) = _putchar;
    int i, count = 0; /* A Cmment lives here*/
    unsigned int _abs_, current;

    if (fd == STDERR_FILENO)
        __putchar = _eputchar; /* A Cmment lives here*/

    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-'); /* A Cmment lives here*/
        count++;
    }
    else
        _abs_ = input; /* A Cmment lives here*/

    current = _abs_;
    for (i = 1000000000; i > 1; i /= 10)
    {
        if (_abs_ / i)
        {
            __putchar('0' + current / i); /* A Cmment lives here*/
            count++;
        }
        current %= i;
    }

    __putchar('0' + current);
    count++; /* A Cmment lives here*/

    return (count);
}
