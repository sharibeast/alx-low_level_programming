#include "main.h"

/**
 * check_perfect_sqrt - verify number is its perfect square
 * @n: number
 * @i: average
 * Return: return number if perfect square, else -1
 */
int check_perfect_sqrt(int i, int n)
{
	if (n <= 1)
		return (-1);
	else if (n % 1 == 0 && n / i == i)
		return (i);
	else
		return (check_perfect_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - function that returns the natural square root of a number
 * @n: number to be checked
 * Return: i if perfect square, else -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else if (n < 2)
		return (n);
	else
		return (check_perfect_sqrt(n, 2));
}
