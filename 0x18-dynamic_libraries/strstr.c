#include "main.h"

/**
 * _strstr - function to find substring
 * @haystack: the string to search
 * @needle: the substring
 *
 * Return: if substring found - a pointer to the begining of string
 *         if not found - null
 */
char *_strstr(char *haystack, char *needle)
{
	int i;

	if (*needle == 0)
	{
		return (haystack);
	}
	while (*haystack)
	{
		i = 0;

		if (haystack[i] == needle[i])
		{
			do {
				if (needle[i + 1] == '\0')
				{
					return (haystack);
					i++;
				}
			} while (haystack[i] == needle[i]);
		}
		haystack++;
	}
	return ('\0');
}
