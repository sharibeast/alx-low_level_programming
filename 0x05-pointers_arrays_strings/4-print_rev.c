#include "main.h"
#include <stdio.h>

/**
 * print_rev - function that prints a string, in reverse,.
 * @str: pointer parameter string
 *
 * On error, -1 is returned, and errno is set appropriately.
 */

void print_rev(char *str)
{
	int m = 0;
	int n = 0;

	while (str[m] != '\0')
	{
		m++;
	}
	for (n = m - 1; n >= 0; n--)
	{
		_putchar(str[n]);
	}
	_putchar('\n');
}
