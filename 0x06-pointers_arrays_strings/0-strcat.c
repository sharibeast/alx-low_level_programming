#include "main.h"
/**
 * _strcat - a function to concatenates two strings
 * Description: 'Change pointer value'
 * @dest: Pointer to variable str
 * @src: Pointer variable
 * Return: Character
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
