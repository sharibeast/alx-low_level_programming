#include <stdio.h>

/**
 * _strncpy - function that copies a string
 * Description: 'function that copy string'
 * @dest: Pointer to variable str
 * @n: Pointer variable
 * @src: Pointer variable
 * Return: Character
 */

char *_strncpy(char *dest, char *src, int n)
{
	int j;

	for (j = 0; j < n && src[j] != '\0'; j++)
	{
		dest[j] = src[j];
	}

	for (; j < n; j++)
	{
		dest[j] = '\0';
	}

	return (dest);
}
