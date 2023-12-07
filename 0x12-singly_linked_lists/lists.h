#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct list_s - singly linked list node
 * @str: string stored in the node (malloc'ed string)
 * @len: length of the string
 * @next: pointer to the next node in the list
 *
 * Description: A singly linked list node containing a string and its length.
 */
typedef struct list_s
{
	char *str;               /* string - dynamically allocated */
	unsigned int len;        /* length of the string */
	struct list_s *next;     /* pointer to the next node in the list */
} list_t;

/* _putchar - writes a character to the standard output */
int _putchar(char c);

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h);

/**
 * list_len - Returns the number of elements in a list_t list.
 * @h: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t list_len(const list_t *h);

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Pointer to the pointer to the head of the list.
 * @str: String to be stored in the new node.
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str);

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Pointer to the pointer to the head of the list.
 * @str: String to be stored in the new node.
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str);

/**
 * free_list - Frees a list_t list.
 * @head: Pointer to the head of the list.
 */
void free_list(list_t *head);

#endif /* LISTS_H */

