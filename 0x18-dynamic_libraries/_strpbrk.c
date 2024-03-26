#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: Pointer to the string to be searched
 * @accept: Pointer to the string containing the characters to search for
 *
 * Return: Pointer to the first occurrence in `s` of any of the characters
 * in the string `accept`, or NULL if no such character is found
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s)
	{
		char *temp = accept;

		while (*temp)
		{
			if (*s == *temp)
				return (s);
			temp++;
		}
		s++;
	}

	return (NULL);
}
