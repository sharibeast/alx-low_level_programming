#include <stdio.h>

/**
 * int_index - function that searches for an integer.
 * @array: array
 * @size: numbeer of element in array
 * @cmp1-main.c: pointer to the function
 * Return: Int
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0 || array == NULL || cmp == NULL)
	{
		return (-1);
	}

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
	}

	return (-1);
}
