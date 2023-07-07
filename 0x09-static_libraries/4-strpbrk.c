#include "main.h"
/**
 * _strpbrk - a function to search string
 * @s: string to be seached
 * @accept: set of seaches
 *
 * Return: null when not matched
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				return (s);
			}
		}
		s++;
	}
	return ('\0');
}
