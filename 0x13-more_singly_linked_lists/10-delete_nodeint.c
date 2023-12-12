#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Deletes the node at a given index.
 * @head: Pointer to the pointer to the head of the list.
 * @index: Index of the node that should be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	/* If index is 0, delete the head node */
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	temp = *head;
	prev = NULL;

	/* Traverse the list to the specified index */
	for (i = 0; i < index && temp != NULL; i++)
	{
		prev = temp;
		temp = temp->next;
	}

	/* If the index is out of bounds, return -1 */
	if (temp == NULL)
		return (-1);

	/* Remove the node at the specified index */
	prev->next = temp->next;
	free(temp);

	return (1);
}

