#include "main.h"



/**
 * prime_helper - function that helps to calculate prime numbers
 * @n: number
 * @i: interger
 *
 * Return: integer.
 */

int prime_helper(int n, int i)
{
	if (i == 1)
	{
		return (1);
	}
	else if (i > 0 && n % i == 0)
	{
		return (0);
	}
	else
		return (prime_helper(n, i - 1));
}


/**
 * is_prime_number - function that returns 1 if the input integer
 *  is a prime number, otherwise return 0
 * @n: number
 * Return: integer.
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	else
		return (prime_helper(n, n - 1));
}
