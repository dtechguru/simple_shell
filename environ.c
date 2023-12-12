#include "shell.h"
/*dtechguru*/

/**
 * _myenv - show di current environment
 * @info: Structure wey get potential arguments. E dey help us maintain
 * constant function prototype.
 * Author: dtechguru
 * Return: E dey always return 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - get di value of an environ variable
 * @info: Structure wey get potential arguments. E dey help us maintain
 * @name: env var name
 *
 * Author: dtechguru
 * Return: di value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
		/*dtechguru*/
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Start new environment variable,
 *             or modify existing one
 * @info: Structure wey get potential arguments. E dey help us maintain
 * constant function prototype.
 * Author: dtechguru
 * Return: E dey always return 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);	/*dtechguru*/
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove environment variable
 * @info: Structure wey get potential arguments. E dey help us maintain
 * constant function prototype.
 * Author: dtechguru
 * Return: E dey always return 0
 */
int _myunsetenv(info_t *info)
{
	int i;
	/*dtechguru*/

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - Populate env linked list
 * @info: Structure wey get potential arguments. E dey help us maintain
 * constant function prototype.
 * Author: dtechguru
 * Return: E dey always return 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
/*dtechguru*/
