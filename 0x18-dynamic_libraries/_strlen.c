/**
 * _strlen - calculates the length of a string
 * @s: The string to calculate the length of
 *
 * Return: The length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (*s)
	{
		len++;
		s++;
	}

	return (len);
}
