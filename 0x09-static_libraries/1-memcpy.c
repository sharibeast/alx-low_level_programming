#include <stdio.h>

/**
 * _memcpy - function that copies memory area.
 * @dest: destination
 * @src: source
 * @n: unsigned int
 *
 * Return: pointer to destination
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int m;

	char *destination = dest;

	char *source = src;

	for (m = 0; m < n; m++)
	{
		destination[m] = source[m];
	}
	return (dest);
}
