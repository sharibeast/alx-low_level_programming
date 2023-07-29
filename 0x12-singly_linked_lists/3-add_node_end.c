#include "lists.h"

/**
 * add_node_end - function to add node at the node of a linked list
 * @head: head
 * @str: pointer to a string
 *
 * Return: the address of the new element,
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node, *tmp;

	node = malloc(sizeof(list_t));
	if (node == NULL)
	{
		free(node);
		return (NULL);
	}
	tmp = *head;
	node->len = strlen(str);
	node->next = NULL;
	node->str = strdup(str);

	if (!*head)
	{
		*head = node;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (*head);
}
