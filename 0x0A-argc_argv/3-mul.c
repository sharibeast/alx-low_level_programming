#include <stdio.h>
#include "main.h"

/**
 * main - program that multiplies two numbers.
 * @argc: number
 * @argv: array of arguments in the program
 * Return: Always 0
 */

int main(int argc, __attribute__((unused)) char *argv[])
{
	int product;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	product = atoi(argv[1]) * atoi(argv[2]);
	printf("%d\n", product);
	return (0);
}
