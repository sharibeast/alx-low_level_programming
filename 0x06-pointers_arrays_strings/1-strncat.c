#include <stdio.h>

/**
 * _strncat - function that concatenates two strings
 * Description: 'Change pointer value'
 * @dest: Pointer to variable str
 * @n: Pointer variable
 * @src: Pointer variable
 * Return: Character
 */

char *_strncat(char *dest, char *src, int n)
{
	char *p = dest;

	while (*p != '\0')
	{
		p++;
	}
	while (*src != '\0' && n > 0)
	{
		*p = *src;
		p++;
		src++;
		n--;
	}
	*p = '\0';
	return (dest);
}
