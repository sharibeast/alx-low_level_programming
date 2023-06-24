#include <stdio.h>
#include "main.h"

/**
 *print_most_numbers - Entry point
 *Description: 'function that prints the numbers, from 0 to 9'
 * do not print 2 and 4
 *Return: Integer Value 0
 */

void print_most_numbers(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		if (i == 2 || i == 4)
			continue;
		_putchar('0' + i);
	}
	_putchar('\n');
}
