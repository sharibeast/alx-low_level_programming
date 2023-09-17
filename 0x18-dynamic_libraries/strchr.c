#include "main.h"

/**
 * *_strchr - function to return the character
 * @s: memory address
 * @c: character to be located
 *
 * Return: Always 0
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}
	return (0);
}
