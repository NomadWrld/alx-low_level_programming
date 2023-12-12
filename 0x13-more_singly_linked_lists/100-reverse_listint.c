#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Pointer to the pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	while (*head != NULL)
	{
		/* Store the next node */
		next = (*head)->next;

		/* Reverse the link */
		(*head)->next = prev;

		/* Move to the next pair of nodes */
		prev = *head;
		*head = next;
	}

	/* Update the head to point to the last node (prev) */
	*head = prev;

	return (*head);
}

