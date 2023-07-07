#include <stdio.h>
#include "main.h"

/**
 *_isupper - Entry point
 *Description: 'function that checks for uppercase character'
 *@a: parameter passed
 *Return: Integer Value 0
 */
int _isupper(int a)
{
	if (a >= 'A' && a <= 'Z')
		return (1);
	return (0);
}
