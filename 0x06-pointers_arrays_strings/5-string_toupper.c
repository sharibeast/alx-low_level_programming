#include <stdio.h>

/**
 * string_toupper - function that changes all
 * lowercase letters of a string to uppercase.
 * lowercase letters of a string to uppercase
 * Description: 'Change pointer value'
 * @str: Pointer variable
 * Return: Character
 */
char *string_toupper(char *str)
{
	char *p = str;

	while (*p != '\0')
	{
		if (*p >= 'a' && *p <= 'z')
		{
			*p = *p - 'a' + 'A';
		}
		p++;
	}

	return (str);
}
