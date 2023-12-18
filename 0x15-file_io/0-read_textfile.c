#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/* Helper function for file read and write operations */
static ssize_t read_write(int fd, char *buffer, size_t letters);

/**
 * read_textfile - Read text file and print to POSIX standard output
 *
 * @filename: Name of file to read
 * @letters: Number of letters to read and print
 *
 * Return: Actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	/* Open file in read-only mode */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	/* Allocate memory for buffer */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	/* Read and write data from file to standard output */
	bytes_written = read_write(fd, buffer, letters);

	/* Cleanup and return number of bytes written */
	free(buffer);
	close(fd);
	return (bytes_written);
}

/**
 * read_write - Read data from file and write to standard output
 *
 * @fd: File descriptor
 * @buffer: Buffer to store read data
 * @letters: Number of letters to read and print
 *
 * Return: Actual number of letters it could read and print
 */
static ssize_t read_write(int fd, char *buffer, size_t letters)
{
	ssize_t bytes_read, bytes_written;

	/* Read data from file into buffer */
	bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1)
		return (0);

	/* Write data from buffer to standard output */
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
		return (0);

	return (bytes_written);
}

