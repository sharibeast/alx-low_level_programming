#include <stdlib.h>

/**
 * array_range - function that creates an array of integers.
 * @min: integer to be converted
 * @max: integer to be converted
 * Return: Pointer
 */
int *array_range(int min, int max)
{
	int numElements, *arr, i;

	if (min > max)
	{
		return (NULL);
	}

	numElements = max - min + 1;

	arr = malloc(numElements * sizeof(int));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < numElements; i++)
	{
		arr[i] = min;
		min++;
	}

	return (arr);
}
