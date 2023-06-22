#include<stdio.h>
#include "main.h"

/**
 *print_sign- Entry point
 *Description: 'function that prints the sign of a number'
 *Return: Integer Value 0
 *@n: Input as parameter
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	_putchar('0');
	return (0);
}
