#include "lists.h"

/**
 * list_len - Returns the number of elements in a list_t list.
 * @h: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;  /* Counter for the number of nodes */

	while (h != NULL)
	{
		h = h->next;  /* Move to the next node */
		count++;      /* Increment the node count */
	}

	return (count);
}

