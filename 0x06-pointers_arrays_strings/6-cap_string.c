#include "main.h"

/**
 * cap_string - function that capitalizes all words of a string.
 * @str: The string to be capitalized.
 *
 * Return: A pointer to the changed string.
 */

char *cap_string(char *str)
{
	int caps = 1;
	char *p = str;

	while (*p != '\0')
	{
		if (*p >= 'a' && *p <= 'z')
		{
			if (caps)
			{
				*p = *p - 'a' + 'A';
				caps = 0;
			}
		}
		else
		{
			caps = (*p == ' ' || *p == '\t' || *p == '\n' ||
				  *p == ',' || *p == ';' || *p == '.' ||
				  *p == '!' || *p == '?' || *p == '"' ||
				  *p == '(' || *p == ')' || *p == '{' ||
				  *p == '}');
		}

		p++;
	}

	return (str);
}
