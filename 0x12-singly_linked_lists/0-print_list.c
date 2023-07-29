#include "lists.h"
#include <stdio.h>
#include <string.h>


/**
 * print_list - function that prints all the elements of a list_t list.
 * @h: list parameter
 * Return: nodes of the function
 *
 */

size_t list_len(const list_t *h)
{
	size_t node = 0;

	while (h != NULL)
	{
		node++;
		h = h->next;
	}

	return (node);
}
