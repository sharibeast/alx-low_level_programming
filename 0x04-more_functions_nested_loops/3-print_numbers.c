#include <stdio.h>
#include "main.h"

/**
 *print_numbers - Entry point
 *Description: 'function that prints the numbers
 *from 0 to 9, followed by a new line.'
 *Return: Integer Value 0
 */

void print_numbers(void)
{
	int i;

	for (i = 0; i <= 9; i++)
		_putchar('0' + i);
	_putchar('\n');
}
