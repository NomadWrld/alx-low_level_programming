#include <unistd.h>

/**
 * _puts - writes a string to stdout
 * @s: The string to write
 */
void _puts(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}
