#include "main.h"
#include <stdio.h>

/**
 * _abs - function that computes the absolute value of an integer.
 * @num: The number to compute absolute
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _abs(int num)
{
	if (num < 0)
	{
		return (-num);
	}
	else
	{
		return (num);
	}
}
