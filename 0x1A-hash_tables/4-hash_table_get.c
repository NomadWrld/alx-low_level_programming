#include "hash_tables.h"
#include "key_index.h"
#include <stdlib.h>
#include <string.h>

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}
