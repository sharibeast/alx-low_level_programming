#include "main.h"
#define INTEGER_BITS (sizeof(unsigned long int) * 8)

/**
 * set_bit - function that sets the value of a bit to 1 at a given index.
 * @n: pointer
 * @index: index
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > INTEGER_BITS)
	{
		return (-1);
	}
	*n = ((1UL << index) | *n);
	return (1);
}
