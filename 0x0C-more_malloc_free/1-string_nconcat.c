#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - converts a string to an integer
 * @s1: integer to be converted
 * @s2: integer to be converted
 * @n: integer to be converted
 * Return: Pointer
 */
char *string_nconcat(char *s1, char *s2, int n)
{
	int s1_len, s2_len, result_len, i, j;
	char *result;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;

	s2_len = 0;
	while (s2[s2_len] != '\0')
		s2_len++;

	if (n >= s2_len)
		n = s2_len;

	result_len = s1_len + n;
	result = malloc(result_len + 1);
	if (result == NULL)
		return (NULL);

	for (i = 0; i < s1_len; i++)
		result[i] = s1[i];

	for (j = 0; j < n; j++)
		result[i++] = s2[j];

	result[i] = '\0';

	return (result);
}
