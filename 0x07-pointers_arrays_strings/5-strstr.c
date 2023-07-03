#include <stdio.h>

/**
 * _strstr - function that locates a substring.
 * Description: 'unction that locates a substring.'
 * @haystack: haystack param
 * @needle: needle
 * Return:  pointer to the beginning of the located substring, or NULL
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *haystack_pointer = haystack;
		char *needle_pointer = needle;

		while (*haystack_pointer == *needle_pointer && *haystack_pointer
		!= '\0' && *needle_pointer != '\0')
		{
			haystack_pointer++;
			needle_pointer++;
		}

		if (*needle_pointer == '\0')
		{
			return (haystack);
		}

		haystack++;
	}

	return (NULL);
}
