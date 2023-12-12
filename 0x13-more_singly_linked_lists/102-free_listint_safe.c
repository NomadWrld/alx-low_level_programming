#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Pointer to the pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	listint_t *temp;
	size_t count = 0;

	while (current != NULL)
	{
		/* Save the next node */
		temp = current->next;

		/* Free the current node */
		free(current);

		/* Move to the next node */
		current = temp;

		count++;
	}

	/* Set the head to NULL after freeing all nodes */
	*h = NULL;

	return (count);
}

