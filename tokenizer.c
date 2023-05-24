#include "shell.h"
#include <stddef.h>

/**
 * **strtow - it splits a string into words and  repeat delimiters are ignored
 * @str: its the input string
 * @d: its the delimeter string
 * Return: it returns a pointer to an array of strings, or NULL if it fails
 */

char **strtow(char *str, char *d)
{
	int a, b, j, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (is_delim(str[a], d))
			a++;
		j = 0;
		while (!is_delim(str[a + j], d) && str[a + j])
			j++;
		s[b] = malloc((j + 1) * sizeof(char));
		if (!s[b])
		{
			for (j = 0; j < b; j++)
				free(s[j]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < j; n++)
			s[b][n] = str[a++];
		s[b][n] = 0;
	}
	s[b] = NULL;
	return (s);
}

/**
 * **strtow2 - it splits a string into words
 * @str: its the input string
 * @d: its the delimeter
 * Return: its a pointer to an array of strings, or NULL if it fails
 */
char **strtow2(char *str, char d)
{
	int a, b, j, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
				    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		j = 0;
		while (str[a + j] != d && str[a + j] && str[a + j] != d)
			j++;
		s[b] = malloc((j + 1) * sizeof(char));
		if (!s[b])
		{
			for (j = 0; j < b; j++)
				free(s[j]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < j; n++)
			s[b][n] = str[a++];
		s[b][n] = 0;
	}
	s[b] = NULL;
	return (s);
}
