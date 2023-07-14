#include <stdlib.h>

/**
 * _calloc - unction that allocates memory for an array
 * @nmemb: integer to be converted
 * @size: integer to be converted
 * Return: void
 */
void *_calloc(int nmemb, int size)
{
	int total_size;
	void *ptr;
	char *char_ptr;
	int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;

	ptr = malloc(total_size);

	if (ptr == NULL)
		return (NULL);

	char_ptr = (char *)ptr;
	for (i = 0; i < total_size; i++)
		char_ptr[i] = 0;

	return (ptr);
}
