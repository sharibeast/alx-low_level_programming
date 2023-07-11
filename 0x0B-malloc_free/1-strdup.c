#include <stdlib.h>

/**
 * _strdup - function that returns a pointer
 *  to a newly allocated space in memory,
 * @str: string
 *
 * Return: NULL if str = NULL
 */
char *_strdup(char *str)
{
	size_t length, i;
	char *duplicate;

	if (str == NULL)
	{
		return (NULL);
	}

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	duplicate = (char *)malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= length; i++)
	{
		duplicate[i] = str[i];
	}

	return (duplicate);
}
