#include "key_index.h"
#include <string.h>

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash = 0;
	unsigned long int i;

	for (i = 0; i < strlen((const char *)key); i++)
	{
		hash = (hash + key[i]) % size;
	}

	return (hash);
}
