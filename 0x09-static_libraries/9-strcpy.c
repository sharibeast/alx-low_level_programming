#include "main.h"
#include <stdio.h>

/**
 * _strcpy -  function that copies the string pointed to by src,
 * @dest: pointer parameter
 * @src: source
 *
 * Return: character
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
