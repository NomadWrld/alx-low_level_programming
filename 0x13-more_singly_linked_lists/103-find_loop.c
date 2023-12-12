#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	if (head == NULL || head->next == NULL)
		return (NULL);

	tortoise = head;            /* Move by one step */
	hare = head;                /* Move by two steps */

	while (hare && hare->next)
	{
		tortoise = tortoise->next;      /* Move by one step */
		hare = hare->next->next;        /* Move by two steps */

		/* Loop detected */
		if (tortoise == hare)
		{
			tortoise = head;            /* Reset one pointer to the head */

			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}

			return (tortoise);          /* Node where the loop starts */
		}
	}

	return (NULL);                     /* No loop found */
}

