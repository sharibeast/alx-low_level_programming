#include "lists.h"

/**
 * looplist -  loop list
 * @head: pointer  first element
 *
 * Return: val
 */
size_t loop(const listint_t *head)
{
	size_t node = 1;
	const listint_t *firstNode, *secondNode;

	if (head == NULL || head->next == NULL)
	{
		return (0);
	}
	firstNode = head->next;
	secondNode = head->next->next;

	while (secondNode)
	{
		if (secondNode == firstNode)
		{
			firstNode = head;
			while (secondNode != firstNode)
			{
				node++;
				firstNode = firstNode->next;
				secondNode = secondNode->next;
			}
			firstNode = firstNode->next;
			while (firstNode != secondNode)
			{
				node++;
				firstNode = firstNode->next;
			}
			return (node);
		}

		firstNode = firstNode->next;
		secondNode = secondNode->next->next;
	}
	return (0);
}

/**
 * print_listint_safe - function that prints a listint_t linked list.
 * @head: pointer  element
 * Return: nodes list no
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node, counter = 0;

	node = loop(head);
	if (node == 0)
	{
		for (node = 0; head != NULL; node++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (counter = 0; counter < node; counter++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (node);
}
