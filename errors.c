#include "shell.h"
/*dtechguru*/

/**
 * _eputs - show an input string, abeg
 * @str: di string to be printed
 * Author: dtechguru
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - write di character c to stderr
 * @c: Di character wey we won print
 * Author: dtechguru
 * Return: On success 1.
 * On error, -1 dey returned, and errno go dey set accordingly.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - write di character c to given fd
 * @c: Di character wey we won print
 * @fd: Di filedescriptor wey we won write to
 * Author: dtechguru
 * Return: On success 1.
 * On error, -1 dey returned, and errno go dey set accordingly.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - show an input string
 * @str: di string to be printed
 * @fd: di filedescriptor to write to
 * Author: dtechguru
 * Return: di number of chars wey dem put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
		/*dtechguru*/
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
/*dtechguru*/
