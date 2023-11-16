#include "shell.h"

/**
 * **strtow - ignoring repeated delimiters,splits string into words
 * @str: input string
 * @d: delimeter string
 * Return: a pointer to an array of strings, or NULL if failed
 */

char **strtow(char *str, char *d)
{
	int m, n, o, p, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (m = 0; str[m] != '\0'; m++)
		if (!is_delim(str[m], d) && (is_delim(str[m + 1], d) || !str[m + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (m = 0, n = 0; n < numwords;  n++)
	{
		while (is_delim(str[m], d))
			m++;
		o = 0;
		while (!is_delim(str[m + o], d) && str[m + o])
			o++;
		s[n] = malloc((o + 1) * sizeof(char));
		if (!s[n])
		{
			for (o = 0; o < n; o++)
				free(s[o]);
			free(s);
			return (NULL);
		}
		for (p = 0; p < o; p++)
			s[n][p] = str[m++];
		s[n][p] = 0;
	}
	s[n] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, t, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (t = 0; t < k; t++)
			s[j][t] = str[i++];
		s[j][t] = 0;
	}
	s[j] = NULL;
	return (s);
}
