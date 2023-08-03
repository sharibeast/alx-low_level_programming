#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index.
 * @n: numbr
 * @index: index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int val;

	if (index > 63)
	{
		return (-1);
	}

	val = 1 << index;
	return ((n & val) > 0);
}
