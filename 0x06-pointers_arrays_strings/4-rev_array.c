#include <stdio.h>

/**
 * reverse_array - function that reverses the content of an array of integers.
 * Description: 'Change pointer value'
 * @a: Pointer to string
 * @n: Pointer to string
 * Return: Int
 */
void reverse_array(int *a, int n)
{
	int temp, i;

	for (i = 0; i < n / 2; i++)
	{
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
