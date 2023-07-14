#include "main.h"
#include <stdlib.h>

/**
 * ext_code - exit the codes
 */
void ext_code(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * _valid - checks if the character of string is correct
 * @s: given character of string
 */
void _valid(char *s)
{
	int i = 0;

	if (s[i] == '-')
		i = 1;
	for (; s[i] != '\0'; i++)
		if (s[i] < 48 || s[i] > 57)
			ext_code();
}

/**
 * to_lon - converts string to long
 * @s: address of the string
 * Return: address of the string
 */
long int to_lon(char *s)
{
	long int sum = 0;
	int i = 0, sign = 1;

	if (s[i] == '-')
	{
		sign = -1;
		i = 1;
	}

	for (; s[i] != '\0'; i++)
		sum = (sum * 10) + (s[i] % 48);

	sum *= sign;
	return (sum);
}

/**
 * print_nums - outputs the large number
 * @n: large number
 */
void print_nums(long int n)
{
	long int temp = n;
	char *s;
	int i = 0;

	s = malloc(sizeof(char) * 100);
	if (n < 0)
	{
		temp *= -1;
		_putchar('-');
	}
	while (temp != 0)
	{
		s[i] = (temp % 10) + '0';
		i++;
		temp /= 10;
	}

	while (i >= 0)
	{
		_putchar(s[i]);
		--i;
	}

	_putchar('\n');
}

/**
 * main - main function
 * @argc: number of argument
 * @argv: array of arguments
 *
 * Return: 0;
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		ext_code();

	_valid(argv[1]);
	_valid(argv[2]);

	print_nums(to_lon(argv[1]) * to_lon(argv[2]));

	return (0);
}
