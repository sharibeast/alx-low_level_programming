#include <stdio.h>
#include "main.h"

/**
 * main - program that prints the minimum
 * number of coins to make change for an amount of money.
 * @argc: number
 * @argv: array of arguments in the program
 * Return: Always 0
 */


int main(int argc, char const *argv[])
{
	int cents;
	int numberOfCoins = 0;

	printf("argc ni %d \n", argc);
	if (argc == 1 || argc > 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);

	while (cents > 0)
	{
		if (cents >= 25)
		{
			cents = cents - 25;
		}
		else if (cents >= 10)
		{
			cents = cents - 10;
		}
		else if (cents >= 5)
		{
			cents = cents - 5;
		}
		else if (cents >= 2)
		{
			cents = cents - 2;
		}
		else if (cents >= 1)
		{
			cents = cents - 1;
		}
		numberOfCoins = numberOfCoins + 1;
	}
	printf("%d\n", numberOfCoins);
	return (0);
}
