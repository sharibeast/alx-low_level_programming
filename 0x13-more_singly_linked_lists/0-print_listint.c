#include "lists.h"

/**
 * print_listint - unction that prints all the elements of a listint_t list.
 * @h: pointer to list
 *
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t numberOfNodes = 0;

	while (h)
	{
		printf("%d\n", h->n);
		numberOfNodes++;
		h = h->next;
	}
	return (numberOfNodes);
}
