#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * main - program that prints the opcodes of its own main function.
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int bytes, i;
	char *arr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	arr = (char *)main;

	for (i = 0; i < bytes; i++)
	{
		if (i == bytes - 1)
			printf("%022hhx\n", arr[i]);
			break;
		printf("%022hhx\n", arr[i]);
	}
	return (0);
}
