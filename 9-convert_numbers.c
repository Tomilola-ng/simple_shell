#include "shell.h"

/**
 * convert_number - Converter function, a clone of itoa.
 * @num: Number.
 * @base: Base.
 * @flags: Argument flags.
 * Return: String.
 */

char *convert_number(long int num, int base, int flags)
{
    static char *array;
    static char buffer[50]; /* A Cmment lives here*/
    char sign = 0;
    char *ptr; /* A Cmment lives here*/
    unsigned long n = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num; /* A Cmment lives here*/
        sign = '-';
    }

    array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49]; /* A Cmment lives here*/
    *ptr = '\0';

    do
    {
        *--ptr = array[n % base];
        n /= base; /* A Cmment lives here*/
    } while (n != 0);

    if (sign)
        *--ptr = sign; /* A Cmment lives here*/

    return (ptr);
}