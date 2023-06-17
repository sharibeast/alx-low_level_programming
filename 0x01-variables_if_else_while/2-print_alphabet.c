#include <stdio.h>

/**
 * main -Entry point
 * Description: 'The function to print alphabeet char in lowercase'
 * Return: Returns zero int
 */

int main(void)
{
	char init = 'a';

	for (init = 'a'; init <= 'z'; init++)
		putchar(init);
	putchar('\n');
	return (0);
}
