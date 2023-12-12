#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Pointer to the pointer to the head of the list.
 * @idx: Index of the list where the new node should be added.
 * @n: Integer data for the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp;
	unsigned int i;

	/* Create a new node and set its data */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	/* If idx is 0, set the new node as the head */
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list to the position before idx */
	temp = *head;
	for (i = 0; i < idx - 1 && temp != NULL; i++)
		temp = temp->next;

	/* If idx is out of bounds, free the new node and return NULL */
	if (temp == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Insert the new node at the specified index */
	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}

