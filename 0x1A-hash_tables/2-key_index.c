#include "hash_tables.h"

/**
 * key_index - Gets the index of a key in a hash table array
 * @key: The key string
 * @size: The size of the hash table array
 *
 * Return: Index where the key should be stored in the array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	/* Get the hash value using hash_djb2 function */
	hash_value = hash_djb2(key);

	/* Compute the index using modulo operator with the array size */
	return (hash_value % size);
}
