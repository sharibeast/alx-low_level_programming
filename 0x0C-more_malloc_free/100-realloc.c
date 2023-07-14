#include <stdlib.h>

/**
 * _realloc - function that reallocates a memory
 * block using malloc and free
 * @ptr: integer to be converted
 * @old_size: integer to be converted
 * @new_size: integer to be converted
 * Return: Pointer
 */
void *_realloc(void *ptr, int old_size, int new_size)
{
	void *new_ptr;
	char *char_ptr, *new_char_ptr;
	int copy_size, i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		exit(1);

	char_ptr = (char *)ptr;
	new_char_ptr = (char *)new_ptr;
	copy_size = old_size < new_size ? old_size : new_size;
	for (i = 0; i < copy_size; i++)
		new_char_ptr[i] = char_ptr[i];

	free(ptr);

	return (new_ptr);
}
