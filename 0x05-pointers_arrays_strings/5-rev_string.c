#include "main.h"
#include <stdio.h>

/**
 * rev_string -  function that copies the string pointed to by src,
 * @s: pointer parameter
 * Return: character
 * On error, -1 is returned, and errno is set appropriately.
 */
void rev_string(char *s)
{
	char *start = s;
	char *end = s;

	while (*end != '\0')
	{
		end++;
	}

	end--;

	while (start < end)
	{
		char temporary = *start;

		*start = *end;

		*end = temporary;

		start++;

		end--;
	}
}
