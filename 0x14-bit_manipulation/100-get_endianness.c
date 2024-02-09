#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int test = 1;
	char *endian_check = (char *)&test;

	/* If first byte is 1, it's little endian; otherwise, it's big endian */
	return (*endian_check);
}
