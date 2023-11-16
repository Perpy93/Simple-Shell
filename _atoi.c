#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 *
 * @info: struct address
 *
 * Return: if interactive mode return 1, 0 if not
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - ascertain if  character is delimeter
 * @c: character to check
 * @delim: delimeter string
 * Return: if true return 1, and if false 0
 */
int is_delim(char c, char *delim)
{
	if (*delim)
		while (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - looks out for alphabetic character
 *@c: character to input
 *Return: if c is alphabetic returns 1 and 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - function that convert a string to integer
 *@s: string to be converted
 *Return: 0 if string have no number, otherwise converted numbers
 */

int _atoi(char *s)
{
	int t, sign = 1, flag = 0, number;
	unsigned int i = 0;

	for (t = 0;  s[t] != '\0' && flag != 2; t++)
	{
		if (s[t] == '-')
			sign *= -1;

		if (s[t] >= '0' && s[t] <= '9')
		{
			flag = 1;
			i *= 10;
			i += (s[t] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		number = -i;
	else
		number  = i;

	return (number);
}
