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
	char *a;
	unsigned int lenght1, length2;
	unsigned int i, m;
	char nul = '\0';
	int total;

	if (s1 == NULL)
		s1 = &nul;
	if (s2 == NULL)
		s2 = &nul;

	lenght1 = _strlen(s1);
	length2 = _strlen(s2);

	if (n >= length2)
		total = length2 + lenght1;
	else
		total = lenght1 + n;

	a = malloc(total + 1);
	if (a == NULL)
		return (NULL);

	i = 0, m = 0;
	while (s1[i] != '\0')
		a[m++] = s1[i++];
	i = 0;
	while (s2[i] != '\0' && n-- != 0)
		a[m++] = s2[i++];
	a[m] = '\0';

	return (a);
}
