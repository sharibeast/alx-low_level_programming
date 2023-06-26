#include "main.h"
#include <stdio.h>

/**
 * puts_half - function that prints half of a string, followed by a new line
 * @str: pointer parameter
 * On error, -1 is returned, and errno is set appropriately.
 */

void puts_half(char *str)
{

	char *end = str;

	int i, length, start_index;

	while (*end != '\0')
	{
		end++;
	}

	length = end - str;

	if (length % 2 == 0)
	{
		start_index = length / 2;
	}
	else
	{
		start_index = (length + 1) / 2;
	}

	for (i = start_index; i < length; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
