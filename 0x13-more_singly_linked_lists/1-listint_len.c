#include "lists.h"

/**
 * listint_len -  function that returns the number of elements in a linked
 * @h: pointer to linked list
 *
 * Return: number
 */
size_t listint_len(const listint_t *h)
{
	size_t countNodes = 0;

	while (h)
	{
		h = h->next;
		countNodes++;
	}
	return (countNodes);
}
