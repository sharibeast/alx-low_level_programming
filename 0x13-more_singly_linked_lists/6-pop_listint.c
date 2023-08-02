#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a listint_t
 * @head: pointer to first element of the list
 *
 * Return: data of the first deleted element
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int nodeData;

	if (*head == NULL)
		return (0);
	tmp = *head;
	nodeData = (*head)->n;
	*head = (*head)->next;
	free(tmp);
	return (nodeData);
}
