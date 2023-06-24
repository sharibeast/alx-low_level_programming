#include <stdio.h>
#include "main.h"

/**
 *print_line - Entry point
 *Description: 'function that draws a straight line in the terminal.'
 *Return: Integer Value 0
 *@a: parameter value
 */

void print_line(int a)
{
	int i;

	if (a <= 0)
	{
		putchar('\n');
		return;
	}

	for (i = 0; i < a; i++)
	{
		putchar('_');
	}
	putchar('\n');
}
