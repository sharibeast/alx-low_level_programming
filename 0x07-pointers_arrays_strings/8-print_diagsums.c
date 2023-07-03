#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - function that prints the sum of
 *  the two
 * diagonals of a square matrix of integers.
 * @a: input diagonal numbers
 * @size: size of square
 *
 * Return: 0
 */
void print_diagsums(int *a, int size)
{
	int diag1;
	int diag2;
	int i;
	int n;

	diag1 = 0;
	diag2 = 0;

	for (i = 0; i <= (size * size); i = i + size + 1)
	{
		diag1 = diag1 + a[i];
	}

	for (n = size - 1; n <= (size * size) - size; n = n + size - 1)
	{
		diag2 += a[n];
	}

	printf("%d, %d\n", diag1, diag2);
}
