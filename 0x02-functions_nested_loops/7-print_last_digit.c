#include<stdio.h>
#include "main.h"

/**
 *print_last_digit- Entry point
 *Description: ' prints the last digit of a number'
 *Return: Integer Value 0
 *@number: parameter numbers
 */

int print_last_digit(int number)
{
	int last_digit = number % 10;

	if (last_digit < 0)
	{
		last_digit *= -1;
	}

	_putchar('0' + last_digit);

	return (last_digit);
}
