#include "lists.h"


/**
 * print_dlistint - print all elements available in list
 * @h: pptr head
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t m = 0;
	const dlistint_t *tmp = h;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		m++;
	}
}
