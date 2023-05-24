#include "shell.h"

/**
 **_strncpy - it copies a string
 *@dest: its the destination string to be copied to
 *@src: its the source string
 *@n: its the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, k;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		k = a;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, k;
	char *s = dest;

	a = 0;
	k = 0;
	while (dest[a] != '\0')
		a++;
	while (src[k] != '\0' && k < n)
	{
		dest[a] = src[k];
		a++;
		k++;
	}
	if (k < n)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
