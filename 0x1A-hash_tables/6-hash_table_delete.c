#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	if (ht == NULL)
		return;

	/* Free each node in the hash table's array */
	for (unsigned long int i = 0; i < ht->size; i++)
	{
		hash_node_t *node = ht->array[i];

		while (node != NULL)
		{
			hash_node_t *next = node->next;

			free(node->key);
			free(node->value);
			free(node);
			node = next;
		}
	}

	/* Free the array itself */
	free(ht->array);

	/* Free the hash table structure */
	free(ht);
}
