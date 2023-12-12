#include "shell.h"

/**
 * _myexit - abeg, make di shell comot
 * @info: Structure wey get potential arguments. E dey help us maintain
 * function prototype wey dey constant.
 * Author: dtechguru
 * Return: E go comot wit di exit status wey you give
 * (0) if info.argv[0] no be "exit"
 */
int _myexit(info_t *info)
{
	/* If exit argument dey, check am */
	if (info->argv[1]) 
	{
		int exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - change di current directory of di process, abeg!
 * @info: Structure wey get potential arguments. E dey help us maintain
 * function prototype wey dey constant.
 * Author: dtechguru
 * Return: E dey always return 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: wetin this one suppose be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: wetin this one suppose be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - abeg, epp change di current directory of di process
 * @info: Structure wey get potential arguments. E dey help us maintain
 * function prototype wey dey constant.
 * Author: dtechguru
 * Return: E dey always return 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function never still ready, abeg! \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

