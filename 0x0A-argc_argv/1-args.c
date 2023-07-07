#include <stdio.h>

/**
 * main - function that prints the number of arguments passed into it.
 * @argc: number
 * @argv: array of arguments in the program
 * Return: Always 0
 */

int main(int argc, __attribute__((unused)) char *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
}
