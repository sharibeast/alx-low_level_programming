#include "hash_tables.h"

/**
 * hash_table_get - function to return value with key
 * @ht: pointer to the hash table
 * @key: key of the hash
 *
 * Return: pointer or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *my_node;
	unsigned long int i;

	if (ht == NULL || key == NULL)
		return (NULL);
	i = key_index((const unsigned char *)key, ht->size);
	my_node = ht->array[i];
	while (my_node)
	{
		if (strcmp(my_node->key, key) == 0)
			return (my_node->value);
		my_node = my_node->next;
	}
	return (NULL);
}
