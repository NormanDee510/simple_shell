#include "shell.h"

/**
 * _strcpy - it copies a string
 * @dest: its the destination
 * @src: its the source
 *
 * Return: A pointer to a destination
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = 0;
	return (dest);
}

/**
 * _strdup - it duplicates a string
 * @str: its the string to duplicate
 *
 * Return: A pointer to a duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *lib;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	lib = malloc(sizeof(char) * (len + 1));
	if (!lib)
		return (NULL);
	for (len++; len--;)
		lib[len] = *--str;
	return (lib);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int count = 0;

	if (!str)
		return;
	while (str[count] != '\0')
	{
		_putchar(str[count]);
		count++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int count;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || count >= WRITE_BUF_SIZE)
	{
		write(1, buf, count);
		count = 0;
	}
	if (c != BUF_FLUSH)
		buf[count++] = c;
	return (1);
}
