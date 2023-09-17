#include "main.h"

/**
 * *_memset - function filling the memory
 * @s: memory area
 * @b: character to thefill memory
 * @n: number of memory copy (param)
 * Return: return pointer to the memory
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
