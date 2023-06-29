#include "main.h"

/**
 * _strcat - function appends the src string to the dest string,
 * @dest: destination
 * @src: src
 *
 * Return: a pointer of concatinated string
 */
char *_strcat(char *dest, char *src)
{
	int m, n;

	m = 0;
	n = 0;

	while (dest[m] != '\0')
		m++;

	while (src[n] != '\0')
	{
		src[n] = dest[m];
		n++;
		m++;
	}

	dest[m] = '\0';

	return (dest);
}
