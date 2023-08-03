#include "main.h"

/**
 * get_endianness - function that checks the endianness.
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int ans;
	unsigned int value = 1;
	unsigned char *ptr = (unsigned char *)&value;

	ans = ((*ptr == 1) ? 1 : 0);

	return (ans);
}
