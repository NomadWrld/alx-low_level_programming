#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: Pointer to the pointer to the head of the list.
 *
 * Return: The head node’s data (n), or 0 if the linked list is empty.
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	/* Return 0 if the list is empty */
	if (*head == NULL)
		return (0);

	/* Save the data of the head node */
	data = (*head)->n;

	/* Move the head to the next node */
	temp = *head;
	*head = (*head)->next;

	/* Free the original head node */
	free(temp);

	return (data);
}

