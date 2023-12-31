#include "shell.h"
/*dtechguru*/

/**
 * _myhistory - show di history list, one command by line, with line
 * numbers, starting at 0.
 * @info: Structure wey get potential arguments. E dey help us maintain
 * constant function prototype.
 * Author: dtechguru
 * Return: E dey always return 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - set alias to string
 * @info: parameter struct
 * @str: di alias string
 *
 * Author: dtechguru
 * Return: E dey always return 0 if e succeed, 1 if e fail
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);	/*dtechguru*/
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - set alias to string
 * @info: parameter struct
 * @str: di alias string
 *
 * Author: dtechguru
 * Return: E dey always return 0 if e succeed, 1 if e fail
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - print alias string
 * @node: di alias node
 *
 * Author: dtechguru
 * Return: E dey always return 0 if e succeed, 1 if e fail
 */
int print_alias(list_t *node)
	/*dtechguru*/
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - e be like say na alias command for man page
 * @info: Structure wey get potential arguments. E dey help us maintain
 * constant function prototype.
 * Author: dtechguru
 * Return: E dey always return 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
		/*dtechguru*/
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
		/*dtechguru*/
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	/*dtechguru*/
	return (0);
}

