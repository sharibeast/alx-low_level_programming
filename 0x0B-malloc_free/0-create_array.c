#include <stdlib.h>

/**
 * create_array - function that creates an arrayOfCharacters
 * of chars, and initializes it with a specific char.
 * @size: string
 * @c: char
 *
 * Return: a pointer to the arrayOfCharacters, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *arrayOfCharacters;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}

	arrayOfCharacters = (char *)malloc(size * sizeof(char));
	if (arrayOfCharacters == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		arrayOfCharacters[i] = c;
	}

	return (arrayOfCharacters);
}
