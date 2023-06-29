#include <stdio.h>

/**
 * _strcmp - function that compares two strings
 * Description: 'Change pointer value'
 * @s1: variable str1
 * @s2: variable str2
 * Return: Always Integer
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s2++;
		s1++;
	}

	return (*s1 - *s2);
}
