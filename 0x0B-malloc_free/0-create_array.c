/**
 * create_array Creates an array of chars,
 * it initializes it with a specific char.
 * *size* size of the array
 * *c* char to initialize
 * *return*  pointer to NULL/ array initalized */

char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	str = malloc(sizeof(char) * size);
	if (size == 0 || str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		str[i] = c;
	return (str);
}
