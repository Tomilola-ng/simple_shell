#include "main.h"

/**
 * _myexit - Exits the shell.
 * @info: Structure containing potential arguments.
 * Return: Exits with a given exit status (0) if info.argv[0] != "exit".
 */

int _myexit(info_t *info)
{
	/* Major Code Block: Check if there is an exit argument */
	if (info->argv[1])
	{
		/* Convert exit argument to integer */
		int exitcheck = _erratoi(info->argv[1]);

		/* If conversion fails */
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}

		/* Set exit status and error number */
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}

	/* No exit argument provided */
	info->err_num = -1;
	return (-2);
}

/**
 * _myhelp - Displays help information.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */

int _myhelp(info_t *info)
{
	/* Major Code Block: Display help information */
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
