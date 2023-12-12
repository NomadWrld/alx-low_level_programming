#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	const listint_t *check = head;
	size_t count = 0;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);

		/* Move two steps with 'check' */
		check = check->next;
		if (check != NULL)
			check = check->next;

		/* Move one step with 'current' */
		current = current->next;

		/* If there's a loop, break the loop and exit with status 98 */
		if (current == check)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			exit(98);
		}

		count++;
	}

	return (count);
}

