#include "hash_tables.h"

/**
 * key_index - function to create index of key
 * @key: key of the hash
 * @size: size of the hash table
 *
 * Return: index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int my_hash;

	my_hash = hash_djb2(key);
	return (my_hash % size);
}
