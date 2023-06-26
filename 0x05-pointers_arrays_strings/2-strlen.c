#include "main.h"
#include <stdio.h>

/**
 * _strlen - function that returns the length of a string.
 * @s: pointer parameter
 *
 * Return: length of str
 * On error, -1 is returned, and errno is set appropriately.
 */

int _strlen(char *s)
{
	int length;

	length = 0;

	while (*s != '\0')
	{
		length = length + 1;
		s = s + 1;
	}

	return (length);
}
