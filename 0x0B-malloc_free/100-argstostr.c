#include <stdlib.h>
#include <string.h>

/**
 * argstostr - function that concatenates all the arguments of your program.
 * @ac: string to be converted
 * @av: string to be converted
 *
 * Return: the int converted from the string
 */

char *argstostr(int ac, char **av)
{
	size_t total_len, i, length;
	char *result;
	int i;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	total_len = 0;
	for (i = 0; i < ac; i++)
	{
		total_len += strlen(av[i]) + 1;
	}

	result = (char *)malloc((total_len + 1) * sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}

	i = 0;
	for (i = 0; i < ac; i++)
	{
		length = strlen(av[i]);
		strcpy(result + i, av[i]);
		i += length;
		result[i++] = '\n';
	}

	result[total_len] = '\0';

	return (result);
}