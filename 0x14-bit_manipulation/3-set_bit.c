#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the number to modify.
 * @index: Index of the bit to set (starting from 0).
 *
 * Return: 1 if successful, -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	/* Set  bit at given index using OR with the corresponding mask */
	*n |= (1UL << index);

	return (1);
}

