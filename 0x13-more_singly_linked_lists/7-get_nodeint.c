#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth node of
 *  a listint_t linked list.
 * @head: pointer
 * @index: index
 *
 * Return: the node in the list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *tmp;
	unsigned int n = 0;

	tmp = head;
	while (n < index)
	{
		if (tmp == NULL)
		{
			return (NULL);
		}
		tmp = tmp->next;
		n++;
	}
	return (tmp);
}
