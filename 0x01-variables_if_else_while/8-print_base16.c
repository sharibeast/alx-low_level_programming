#include <stdio.h>

/**
 * main - Entry point
 * Description: 'program that prints all the numbers of base 16 in lowercase'
 * Return: Returns int
 */

int main(void)
{
	int i;
	char init = 'a';

	for (i = 0; i < 10; i++)
		putchar('0' + i);
	for (init = 'a'; init <= 'f'; init++)
		putchar(init);
	putchar('\n');
	return (0);
}
