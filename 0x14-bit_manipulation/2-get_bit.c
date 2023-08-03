#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index.
 * @n: numbr
 * @index: index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int charBits = 8;
	int value;

	if (index > charBits)
	{
		return (-1);
	}
	value = (n >> index) & 1;
	return (value);
}
