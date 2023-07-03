#include <stdio.h>

/**
 * _strpbrk - function that searches a string for any of a set of bytes.
 * @s: Pointer to variable str
 * @accept: Pointer accept
 * Return: a pointer to the byte in s that matches on of bytes in accept
 */

char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		char *ptrAccept = accept;

		while (*ptrAccept != '\0')
		{
			if (*s == *ptrAccept)
			{
				return (s);
			}
			ptrAccept++;
		}
		s++;
	}
	return (NULL);
}
