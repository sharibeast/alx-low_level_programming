#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - function that concatenates two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	size_t lenght1, lenght2, lenght, i;

	char *result;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	lenght1 = 0;
	while (s1[lenght1] != '\0')
	{
		lenght1++;
	}
	lenght2 = 0;
	while (s2[lenght2] != '\0')
	{
		lenght2++;
	}

	lenght = lenght1 + lenght2 + 1;

	result = (char *)malloc(lenght * sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < lenght1; i++)
	{
		result[i] = s1[i];
	}
	for (i = 0; i < lenght2; i++)
	{
		result[lenght1 + i] = s2[i];
	}
	result[lenght1 + lenght2] = '\0';
	return (result);
}
