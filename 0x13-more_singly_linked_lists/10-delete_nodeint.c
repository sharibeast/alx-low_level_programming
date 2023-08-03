#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the nod
 * e at index index of a listint_t linked list.
 * @head: pointer to head
 * @index: index of a node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *currentNode;
	unsigned int j = 1;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(*head);
		return (1);
	}
	while (j < index)
	{
		if (!(*head) || (*head)->next)
		{
			return (-1);
		}
		*head = (*head)->next;
		j++;
	}
	currentNode = (*head)->next;
	(*head)->next = currentNode->next;
	free(currentNode);
	return (1);
}