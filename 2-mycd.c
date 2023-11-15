#include "shell.h"

/**
 * _mycd - Changes the current directory of the process.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */

int _mycd(info_t *info)
{
    char *s, *dir, buffer[1024];
    int chdir_ret; /* Major Code Block: Get current working directory */

    s = getcwd(buffer, 1024);
    if (!s)
        _puts("TODO: >>getcwd failure emsg here<<\n"); /* Major Code Block: Get current working directory */

    /* Check if argv[1] is not provided */
    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME="); /* Major Code Block: Get current working directory */
        if (!dir)
            chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir); /* Major Code Block: Get current working directory */
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        /* Handle '-' case for cd */
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(s);
            _putchar('\n'); /* Major Code Block: Get current working directory */
            return (1);
        }
        _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
        chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
    }
    else
        chdir_ret = chdir(info->argv[1]); /* Major Code Block: Get current working directory */

    /* Check for chdir failure */
    if (chdir_ret == -1)
    {
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]), _eputchar('\n'); /* Major Code Block: Get current working directory */
    }
    else
    {
        /* Update environment variables on successful cd */
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024)); /* Major Code Block: Get current working directory */
    }
    return (0);
}
