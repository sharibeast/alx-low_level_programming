#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/**
 * string_nconcat - check the code
 * @s1: first string
 * @s2: second string
 * @n: size of second string  to copy
 *
 * Return: concantenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int len1, len2, res, i, j;
	char *result;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = 0;
	while (s1[len1] != '\0')
		len1++;

	len2 = 0;
	while (s2[len2] != '\0')
		len2++;

	if (n >= len2)
		n = len2;

	res = len1 + n;
	result = malloc(res + 1);
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	for (j = 0; j < n; j++)
		result[i++] = s2[j];

	result[i] = '\0';

	return (result);
}
