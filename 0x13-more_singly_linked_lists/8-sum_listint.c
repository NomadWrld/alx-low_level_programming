#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data (n) of a listint_t list.
 * @head: Pointer to the head of the list.
 *
 * Return: The sum of all the data, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	/* Traverse the list and add the data of each node to the sum */
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

