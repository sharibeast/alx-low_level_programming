#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/**
 * string_nconcat - check the code
 * @s1: first string
 * @s2: second string
 * @n: size of second string  to copy
 *
 * Return: Always 0.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	if (n >= strlen(s2))
		ptr = malloc(sizeof(char) * (sizeof(s1) + strlen(s1)));
	else
		ptr = malloc(sizeof(char) * (sizeof(s1) + n));

	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}

	for (i = 0; s1[i] != '\0'; i++)
		ptr[i] = s1[i];

	for (j = 0; s2[j] != '\0' && j < n; j++, i++)
		ptr[i] = s2[j];

	ptr[i] = '\0';

	return (ptr);
}
