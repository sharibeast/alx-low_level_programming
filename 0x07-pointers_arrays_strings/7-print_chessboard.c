#include <stdio.h>

/**
 * print_chessboard - function that prints the chessboard
 * Description: ''
 * @a: params
 * Return: void
 */

void print_chessboard(char (*a)[8])
{

	int m, n;

	for (m = 0; m < 8; m++)
	{
		for (n = 0; n < 8; n++)
		{
			printf("%c", a[m][n]);
		}
		printf("\n");
	}
}
