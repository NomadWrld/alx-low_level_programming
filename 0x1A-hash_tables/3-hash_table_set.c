#include "hash_tables.h"
#include "key_index.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table to update or add to.
 * @key: The key. Cannot be an empty string.
 *@value: Value associated with the key, to be duplicated (can be empty)
 *
 * Return: 1 on success, 0 on failure.
 */

/* Forward declaration */
hash_node_t *create_node(const char *key, const char *value);

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	new_node = create_node(key, value);

	if (new_node == NULL)
		return (0);

	/* Insert new_node into hash table */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	return (new_node);
}

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash = 0;
	unsigned long int i;

	for (i = 0; i < strlen((const char *)key); i++)
	{
		hash = (hash + key[i]) % size;
	}

	return (hash);
}
