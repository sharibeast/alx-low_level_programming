#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - function that returns a
 * pointer to a 2 dimensional array of integers.
 * @width: grid rows
 * @height: grid columns
 * Return: pointer to a grid of 2D array.
 */

int **alloc_grid(int width, int height)
{
	int **twoDimensionG;
	int i, j;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	twoDimensionG = malloc(sizeof(int *) * height);

	if (twoDimensionG == NULL)
	{
		free(twoDimensionG);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		twoDimensionG[i] = (int *)malloc(sizeof(int) * width);

		if (twoDimensionG[i] == NULL)
		{
			for (; i >= 0; i--)
				free(twoDimensionG[i]);
			free(twoDimensionG);
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			twoDimensionG[i][j] = 0;

	return (twoDimensionG);


}
