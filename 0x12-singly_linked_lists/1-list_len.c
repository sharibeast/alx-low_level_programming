#include <stdio.h>
#include <string.h>
#include "lists.h"

/**
 * list_len - function that returns the number
 * of elements in a linked list_t list.
 *@h: number of parameters
 * Return: 0 if n = 0, sum otherwise.
 */

size_t list_len(const list_t *h)
{
	size_t countNode = 0;

	while (h != NULL)
	{
		countNode++;
		h = h->next;
	}

	return (countNode);
}
