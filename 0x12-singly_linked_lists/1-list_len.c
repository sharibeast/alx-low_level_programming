#include "lists.h"
#include <stdio.h>
#include <string.h>

/**
 * list_len - function that returns the number of elements
 * in a linked list_t list.
 * @h: pointer to header
 * Return: length of list
 */

size_t list_len(const list_t *h)
{
	size_t node_c = 0;

	while (h != NULL)
	{
		node_c++;
		h = h->next;
	}

	return (node_c);
}
