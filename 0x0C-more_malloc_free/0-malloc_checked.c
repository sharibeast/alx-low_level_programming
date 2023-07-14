#include <stdlib.h>

/**
 * malloc_checked - converts a string to an integer
 * @b: string to be converted
 * Return: Pointer
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}
