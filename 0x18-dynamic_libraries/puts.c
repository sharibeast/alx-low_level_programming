#include "main.h"
/**
 * _puts- prints out to stdout with new line
 * @str: checked string
 * Return: Always 0
 */
void _puts(char *str)
{
	if (str)
	{
		while (*str)
		{
			_putchar(*str++);
		}
	}
	_putchar('\n');
}
