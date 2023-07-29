#include "lists.h"
#include <stdio.h>

/**
 * print_list - function that prints all the elements of a list_t list.
 * @h: list parameter
 * Return: nodes of the function
 *
 */

size_t print_list(const list_t *h)
{
	size_t my_node = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil) \n");
		}
		else
		{
			printf("[%u] %s \n", h->len, h->str);
		}
		h = h->next;
		my_node++;
	}
}
