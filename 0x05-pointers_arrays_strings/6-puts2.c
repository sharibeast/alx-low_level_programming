#include "main.h"
#include <stdio.h>

/**
 * puts2 - function that prints every other character of a string,
 * @str: pointer parameter
 *  Description: 'description'
 *
 * Return: length of str
 * On error, -1 is returned, and errno is set appropriately.
 */

void puts2(char *str)
{
	int m;

	for (m = 0; str[m] != '\0'; m = m + 2)
	{
		_putchar(str[m]);
	}
	_putchar('\n');
}
