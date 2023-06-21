#include "main.h"
#include <stdio.h>

/**
 * add - function that add tow numbers
 * Description: 'the program that add two numbers'
 * @num1: first number input
 * @num2: Second number input
 *
 * Return: On success total results.
 * On error, -1 is returned, and errno is set appropriately.
 */

int add(int num1, int num2)
{
	int sum;

	sum = num1 + num2;
	return (sum);
}
