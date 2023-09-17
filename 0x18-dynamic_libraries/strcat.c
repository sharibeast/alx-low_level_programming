#include "main.h"

/**
 * _strcat - a function to concatenates two strings
 * @dest: string to append to src
 * @src: string to add to dest
 *
 * Return: a pointer of concatinated string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
