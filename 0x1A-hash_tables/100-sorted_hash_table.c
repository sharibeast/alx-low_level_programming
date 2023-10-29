#include "hash_tables.h"


/**
 * shash_table_create - function to create a sorted hash table.
 * @size: sizesorted hash table.
 *
 * Return: NULL or pointer
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - function to add an element to a sorted hash table.
 * @ht: pointer to the sorted hash table.
 * @key: The key to add
 * @value: value with key.
 *
 * Return: 0 or 1
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *temp;
	char *value_cp;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_cp = strdup(value);
	if (value_cp == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->shead;
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = value_cp;
			return (1);
		}
		temp = temp->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_cp);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_cp);
		free(new);
		return (0);
	}
	new->value = value_cp;
	new->next = ht->array[index];
	ht->array[index] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		temp = ht->shead;
		while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
			temp = temp->snext;
		new->sprev = temp;
		new->snext = temp->snext;
		if (temp->snext == NULL)
			ht->stail = new;
		else
			temp->snext->sprev = new;
		temp->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - function to get the value associated with
 *                   a key in a sorted hash table
 * @ht: pointer to the sorted hash table
 * @key: key of the value
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - function to print sorted hash table in order.
 * @ht: pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *my_node;

	if (ht == NULL)
		return;

	my_node = ht->shead;
	printf("{");
	while (my_node != NULL)
	{
		printf("'%s': '%s'", my_node->key, my_node->value);
		my_node = my_node->snext;
		if (my_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - function to print a sorted hash table in reverse order
 * @ht: pointer to the sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *my_node;

	if (ht == NULL)
		return;

	my_node = ht->stail;
	printf("{");
	while (my_node != NULL)
	{
		printf("'%s': '%s'", my_node->key, my_node->value);
		my_node = my_node->sprev;
		if (my_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - function to delete a sorted hash table.
 * @ht: pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *my_node, *temp;

	if (ht == NULL)
		return;

	my_node = ht->shead;
	while (my_node)
	{
		temp = my_node->snext;
		free(my_node->key);
		free(my_node->value);
		free(my_node);
		my_node = temp;
	}
	free(head->array);
	free(head);
}
