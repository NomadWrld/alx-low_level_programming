#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A string representing a binary number.
 *
 * Return: The converted number, or 0 if there is an invalid character
 * in the string or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	/* Check if the input string is NULL */
	if (b == NULL)
		return (0);

	/* Iterate through each character in the binary string */
	while (*b)
	{
		/* Check for invalid characters */
		if (*b != '0' && *b != '1')
			return (0);

		/* Convert the binary string to an unsigned int */
		result = result * 2 + (*b - '0');
		b++;
	}

	/* Return the converted result */
	return (result);
}

