#include "main.h"

/**
 * clear_bit - Set   value of a bit to 0.
 * @ptr_add: pointer of an unsigned long int.
 * @index: index
 *
 * Return: 1 if success, -1 if dailed.
 */
int clear_bit(unsigned long int *ptr_add, unsigned int index)
{
	unsigned int z;

	if (index > 63)
		return (-1);

	z = 1 << index;

	if (*ptr_add & z)
		*ptr_add ^= z;

	return (1);
}
