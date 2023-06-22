#include<stdio.h>
#include "main.h"

/**
 *_isalpha - Entry point
 *Description: 'Main function to print putchar'
 *@c: Parameter input
 *Return: Integer Value 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
