#include "main.h"

/**
 * _strspn - function to get the length of prefix substring
 * @s: th string to be worked on
 * @accept: the prefix
 *
 * Return: the number of prefix
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				n++;
				break;
			}
			else if (accept[i + 1] == '\0')
			{
				return (n);
			}
		}
		s++;
	}
	return (n);
}
