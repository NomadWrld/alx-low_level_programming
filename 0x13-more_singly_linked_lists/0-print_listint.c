#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	size_t node_count = 0;

	/* Iterate through the list */
	while (h != NULL)
	{
		/* Print the value of the current node */
		printf("%d\n", h->n);

		/* Move to the next node */
		h = h->next;

		/* Increment the node count */
		node_count++;
	}

	return (node_count);
}

