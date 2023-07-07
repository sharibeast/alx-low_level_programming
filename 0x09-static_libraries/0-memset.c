#include <stdio.h>

/**
 * _memset - prints buffer in hexa
 * @s: character pointer
 * @b: character
 * @n : unsign integer
 *
 * Return: pointer s.
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
