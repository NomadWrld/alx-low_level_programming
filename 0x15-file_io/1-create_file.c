#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>

/* Helper function to handle write operations */
static ssize_t write_to_file(int fd, const char *text_content);

/**
 * create_file - Create a file with specified permissions and content
 *
 * @filename: Name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, result;

	if (filename == NULL)
		return (-1);

	/* Open or create the file with read and write permissions for the owner */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	/* Write text content to the file */
	result = write_to_file(fd, text_content);

	/* Close the file */
	close(fd);

	return (result);
}

/**
 * write_to_file - Helper function to handle write operations
 *
 * @fd: File descriptor
 * @text_content: NULL terminated string to write to the file
 *
 * Return: Number of bytes written on success, -1 on failure
 */
static ssize_t write_to_file(int fd, const char *text_content)
{
	ssize_t bytes_written;

	if (text_content == NULL)
		return (0);

	/* Write text content to the file */
	bytes_written = write(fd, text_content, strlen(text_content));
	if (bytes_written == -1)
		return (-1);

	return (bytes_written);
}

