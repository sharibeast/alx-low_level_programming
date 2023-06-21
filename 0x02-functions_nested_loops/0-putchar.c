#include "main.h"
#include <stdio.h>

/**
 *main - Entry point
 *Description : 'Main function that print _putchat followed by a new line'
 *Return: Integer Value 0
 */

int main(void)
{
	char str[] = "_putchar";
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
	return (0);
}
