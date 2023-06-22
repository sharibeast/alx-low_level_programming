#include<stdio.h>
#include "main.h"

/**
 *print_alphabet - Entry point
 *Description: 'Main function'
 *Return: Integer Value 0
 */

void print_alphabet(void)
{
	char start = 'a';

	char end = 'z';

	while (start <= end)
	{
		_putchar(start++);
	}
	_putchar('\n');
}
