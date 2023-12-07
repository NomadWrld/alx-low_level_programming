#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Pointer to the pointer to the head of the list.
 * @str: String to be stored in the new node.
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *temp = *head;

	if (str == NULL)
		return (NULL);

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* Duplicate the string */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Set the length of the string */
	new_node->len = strlen(str);

	/* Set the next pointer of the new node to NULL (as it will be the last) */
	new_node->next = NULL;

	/* If the list is empty, make the new node the head */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list to the last node */
	while (temp->next != NULL)
		temp = temp->next;

	/* Attach the new node at the end of the list */
	temp->next = new_node;

	return (new_node);
}
