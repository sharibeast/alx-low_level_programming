#include "main.h"

/**
 * _puts - function that prints a string, followed by a new line.
 * @str: string pointer parameter
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
	_putchar(*str);
	str = str + 1;
	}
	 _putchar('\n');
}
