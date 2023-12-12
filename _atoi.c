#include "shell.h"

/**
 * interactive - returns true if the shell be in interactive mode
 * @info: struct address, me heartie
 *
 * Return: 1 if the shell be in interactive mode, 0 otherwise, avast!
 */
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the character be a delimeter
 * @c: the char to check, aye aye
 * @delim: the delimeter string, arrr!
 * Return: 1 if true, 0 if false, me matey
 */
int is_delim(char c, char *delim)
{
    while (*delim)
        if (*delim++ == c)
            return (1);
    return (0);
}

/**
 * _isalpha - checks for an alphabetic character, arrr!
 * @c: The character to input, me heartie
 * Return: 1 if c be alphabetic, 0 otherwise, yo ho ho!
 */

int _isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);

    else
        return (0);
}

/**
 * _atoi - converts a string to an integer, me matey
 * @s: the string to be converted, avast!
 * Return: 0 if no numbers in the string, converted number otherwise, yo ho ho!
 * Auhtor: Dtechguru
 */

int _atoi(char *s)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
            sign *= -1;

	/*dtechguru*/
        if (s[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        }
	/*dtechguru*/
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return (output);
}
/*Dtechguru*/
