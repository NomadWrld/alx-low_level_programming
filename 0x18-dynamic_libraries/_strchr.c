#include <stddef.h>

/**
 * _strchr - locates the first occurrence of a character in a string
 * @s: Pointer to the string to be searched
 * @c: The character to search for
 *
 * Return: Pointer to first occurrence of `c` in `s`, or NULL if not found
 * or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (c == '\0')
		return (s);

	return (NULL);
}
