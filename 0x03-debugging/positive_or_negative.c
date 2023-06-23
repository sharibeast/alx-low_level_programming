#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 * @i: parameter passed
 * Description: 'program that chck positive or negative'
 *
 * Return: Always 1 (Success)
 */
void positive_or_negative(int i)
{
	if (i > 0)
	{
		printf("%d is positive\n", i);
	}
	else if (i == 0)
	{
		printf("%d is zero\n", i);
	}
	else
	{
		printf("%d is negative\n", i);
	}
}
