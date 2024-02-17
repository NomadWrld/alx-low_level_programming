#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * open_files - Opens the source and destination files.
 * @argv: The command-line arguments.
 * @fd_from: Pointer to the source file descriptor.
 * @fd_to: Pointer to the destination file descriptor.
 */
void open_files(char *argv[], int *fd_from, int *fd_to)
{
	*fd_from = open(argv[1], O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	*fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		close(*fd_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * copy_files - Copies the content from source file to destination file.
 * @fd_from: The source file descriptor.
 * @fd_to: The destination file descriptor.
 */
void copy_files(int fd_from, int fd_to)
{
	char buffer[BUF_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		exit(98);
	}
}

/**
 * close_files - Closes the source and destination files.
 * @fd_from: The source file descriptor.
 * @fd_to: The destination file descriptor.
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptors\n");
		exit(100);
	}
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	open_files(argv, &fd_from, &fd_to);
	copy_files(fd_from, fd_to);
	close_files(fd_from, fd_to);

	return (0);
}
