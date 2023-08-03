#include "lists.h"

/**
 * insert_nodeint_at_index - function that inserts a new node
 *  at a given position.
 * @head: pointer to a head
 * @idx: index
 * @n: inserted node
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *nodeInserted;
	unsigned int j = 0;

	nodeInserted = malloc(sizeof(listint_t));
	if (nodeInserted == NULL || head == NULL)
	{
		return (NULL);
	}
	nodeInserted->n = n;
	if (j == 0)
	{
		nodeInserted->next = *head;
		*head = nodeInserted;
		return (nodeInserted);
	}
	for (j = 1; head && j <= idx; j++)
	{
		if (j == idx)
		{
			nodeInserted->next = (*head)->next;
			(*head)->next = nodeInserted;
			return (nodeInserted);
		}
		else
			*head = (*head)->next;
	}
	return (NULL);
}
