#include "shell.h"

/**
 * bfree - Function that frees a pointer and NULLs the address
 * @ptr: variable address of the pointer to free
 *
 * Return: value 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

