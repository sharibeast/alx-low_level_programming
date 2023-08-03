#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int.
 * @b: binary number
 * Return: the converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int counter = 0;
	unsigned int value = 0;

	if (!b)
		return (0);
	for (; b[counter]; counter++)
	{
		if (b[counter] < '0' || b[counter] > '1')
		{
			return (0);
		}
		value = 2 * value + (b[counter] - '0');
	}
	return (value);
}
