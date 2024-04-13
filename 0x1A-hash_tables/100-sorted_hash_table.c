#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Forward declarations */
static shash_node_t *create_shash_node(const char *key, const char *value);
static void insert_into_sorted_list(shash_table_t *ht, shash_node_t *new_node);
static unsigned long int key_index(const unsigned char *key, unsigned long int size);

/* Function definitions */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	if (ht == NULL || key == NULL || value == NULL || *key == '\0')
		return (0);

	unsigned long int index = key_index((const unsigned char *)key, ht->size);

	shash_node_t *new_node = create_shash_node(key, value);

	if (new_node == NULL)
		return (0);

	insert_into_sorted_list(ht, new_node);

	/* Insert into hash table array */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	unsigned long int index = key_index((unsigned char *)key, ht->size);
	shash_node_t *node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

void shash_table_print(const shash_table_t *ht)
{
	if (ht == NULL || ht->shead == NULL)
		return;

	printf("{");
	shash_node_t *node = ht->shead;
	int first = 1;

	while (node != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
		node = node->snext;
	}

	printf("}\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
	if (ht == NULL || ht->stail == NULL)
		return;

	printf("{");
	shash_node_t *node = ht->stail;
	int first = 1;

	while (node != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
		node = node->sprev;
	}

	printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
	if (ht == NULL)
		return;

	/* Free each node in the hash table's array */
	for (unsigned long int i = 0; i < ht->size; i++)
	{
		shash_node_t *node = ht->array[i];

		while (node != NULL)
		{
			shash_node_t *next = node->next;

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

/* Helper functions */

static shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *new_node = malloc(sizeof(shash_node_t));

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
	new_node->sprev = NULL;
	new_node->snext = NULL;

	return (new_node);
}

static void insert_into_sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *current = ht->shead;
	shash_node_t *prev = NULL;

	while (current != NULL && strcmp(new_node->key, current->key) > 0)
	{
		prev = current;
		current = current->snext;
	}

	new_node->snext = current;
	new_node->sprev = prev;

	if (prev == NULL)
		ht->shead = new_node;
	else
		prev->snext = new_node;

	if (current == NULL)
		ht->stail = new_node;
	else
		current->sprev = new_node;
}

static unsigned long int key_index(const unsigned char *key, unsigned long int size)

{
	unsigned long int hash = 5381;
	int c;

	while ((c = *key++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash % size);
}
