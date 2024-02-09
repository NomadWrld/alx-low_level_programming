#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The unsigned long int number to print in binary.
 */
void print_binary(unsigned long int n)
{
	/* Initialize a mask with the leftmost bit set to 1 */
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	/* Variable to track if non-zero bit is encountered */
	int found_non_zero = 0;

	/* Check each bit in the number */
	while (mask > 0)
	{
		/* Check if the bit is set (1) */
		if ((n & mask) == mask)
		{
			/* Print 1 if the bit is set */
			_putchar('1');
			found_non_zero = 1;
		}
		else if (found_non_zero || mask == 1)
		{
			/* Print 0 if the bit is not set, after the first non-zero bit */
			_putchar('0');
		}

		/* Shift the mask to the right */
		mask >>= 1;
	}
}

