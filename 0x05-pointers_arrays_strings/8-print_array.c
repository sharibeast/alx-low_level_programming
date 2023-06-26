#include <stdio.h>

/**
 * print_array - function that prints n elements of an array of integers
 * @a: pointer parameter
 * @n: int n
 * On error, -1 is returned, and errno is set appropriately.
 */

void print_array(int *a, int n)
{
	int m;

	for (m = 0; m < n; m++)
	{
		printf("%d", a[m]);

		if (m < n - 1)
			printf(", ");
	}

	printf("\n");
}
