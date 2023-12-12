#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to retrieve, starting at 0.
 *
 * Return: The nth node, or NULL if the node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	/* Traverse the list to the desired index */
	for (i = 0; i < index && head != NULL; i++)
		head = head->next;

	/* Return the node at the specified index or NULL if not found */
	return (head);
}

