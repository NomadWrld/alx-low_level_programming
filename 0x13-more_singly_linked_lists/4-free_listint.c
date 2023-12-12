#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - Frees a listint_t list.
 * @head: Pointer to the head of the list.
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	/* Traverse the list and free each node */
	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

