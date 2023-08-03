#include "main.h"

/**
 * flip_bits - function that returns the number of bits
 * you would need to flip to get from one number to another.
 * @n: number to flip
 * @m: fliped no
 *
 * Return: number
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int numberOfBits = 0;
	unsigned long int numberOfFlips = n ^ m;

	while (numberOfFlips != 0)
	{
		if ((numberOfFlips & 1) == 1)
		{
			numberOfBits++;
		}
		numberOfFlips = numberOfFlips >> 1;
	}
	return (numberOfBits);
}
