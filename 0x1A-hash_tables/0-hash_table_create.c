#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table, or NULL if failure
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht = NULL;
	unsigned long int i;

	/* Allocate memory for the hash table structure */
	ht = malloc(sizeof(hash_table_t));

	if (ht == NULL)
		return (NULL);

	/* Initialize the size of the hash table */
	ht->size = size;

	/* Allocate memory for the array of hash node pointers */
	ht->array = malloc(size * sizeof(hash_node_t *));

	if (ht->array == NULL)
	{
		free(ht); /* Clean up allocated hash table structure */
		return (NULL);
	}

	/* Initialize each element in the array to NULL */
	for (i = 0; i < size; i++)
	{
		ht->array[i] = NULL;
	}

	return (ht);
}
