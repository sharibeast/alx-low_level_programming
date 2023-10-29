#include "hash_tables.h"

/**
 * hash_table_delete - function to delete hash table
 * @ht: pointer to the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head;
	hash_node_t *my_node, *temp;
	unsigned long int i = 0;

	head = ht;
	for (; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			my_node = ht->array[i];
			while (my_node != NULL)
			{
				temp = my_node->next;
				free(my_node->key);
				free(my_node->value);
				free(my_node);
				my_node = temp;
			}
		}
	}
	free(head->array);
	free(head);
}
