#include "main.h"

int prime_helper(int n, int i)
{
	if (i == 1)
	{
		return (1);
	}
	else if (i > 0 && n % i == 0)
	{
		return 0;
	}
	else
		return (prime_helper(n, i - 1));
}

int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	else
		return (prime_helper(n, n - 1));
}