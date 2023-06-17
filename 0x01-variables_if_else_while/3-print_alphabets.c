#include <stdio.h>

/**
 * main - Entry point
 * Description: 'this is a main function where
 * program starts which print print uppercae and lowercase'
 * Return: Return integer value 0
 */
int main(void)
{
	char lowercase = 'a', uppercase = 'A';

	while (lowercase <= 'z')
	{
		putchar(lowercase);
		lowercase++;
	}
	while (uppercase <= 'Z')
	{
		putchar(uppercase);
		uppercase++;
	}
	putchar('\n');
	return (0);
}
