#include "main.h"
#include <stdio.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file;
	size_t len = 0;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	file = fopen(filename, "a");
	if (file == NULL)
		return (-1);

	while (text_content[len] != '\0')
		len++;

	bytes_written = fwrite(text_content, sizeof(char), len, file);
	fclose(file);

	return (bytes_written == len ? 1 : -1);
}
