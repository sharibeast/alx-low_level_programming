#include <stdio.h>

/**
 * main - program that prints its name, followed by a new line
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */


int main(__attribute__((unused)) int argc, char const *argv[])
{
	printf("%s\n", *argv);
	return (0);
}
