#include <stdio.h>

/**
 * main - Entry point
 * Description: 'function to prints all single digit
 * numbers of base 10 starting from 0'
 * Return: return integer 0
 */

int main(void)
{
	int x;

	for (x = 0; x < 10; x++)
	{
		putchar('0' + x);
	}
	putchar('\n');

	return (0);
}
