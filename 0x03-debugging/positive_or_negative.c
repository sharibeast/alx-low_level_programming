#include "main.h"
#include <stdio.h>

/**
 * positiv_or_negative - function that check number if
 * is positive or negative
 *
 * Description: 'a function that check number if its posisitive'
 * @i: number
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
