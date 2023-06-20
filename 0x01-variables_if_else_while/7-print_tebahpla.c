#include <stdio.h>

/**
 * main -Entry point
 * Description: 'The function that prints the lowercase alphabet in reverse'
 * Return: Returns zero int
 */

int main(void)
{
	char init = 'a';

	for (init = 'z'; init >= 'a'; init--)
	{
		putchar(init);
	}
	putchar('\n');
	return (0);
}
