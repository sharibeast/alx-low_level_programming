#include "main.h"
#include <stdlib.h>

/**
 * free_grid - function that frees a 2 dimensional grid
 * @grid: point of 2D array
 * @height: hight
 * Return: pointer to a grid of 2D array.
 */

void free_grid(int **grid, int height)
{

	while (height)
	{
		free(grid[--height]);
	}
	free(grid);
}
