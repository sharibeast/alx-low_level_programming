#include "hash_tables.h"


/**
 * hash_table_print - function to print hash table
 * @ht: pointer to hash table
 *
 * Description: key/value pair to be printed
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *my_node;
	unsigned long int i = 0;
	unsigned char flag = 0;

	if (ht == NULL)
		return;
	printf("{");
	for (; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (flag == 1)
			{
				printf(", ");
			}
			my_node = ht->array[i];
			while (my_node != NULL)
			{
				printf("'%s': '%s'", my_node->key, my_node->value);
				my_node = my_node->next;
				if (my_node != NULL)
					printf(", ");
			}
			flag = 1;
		}
	}
	printf("}\n");
}
