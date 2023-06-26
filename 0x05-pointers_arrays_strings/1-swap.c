/**
 * swap_int - function that swaps the values of two integers.
 * @a: first pointer
 * @b: second pointer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */


void swap_int(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}
