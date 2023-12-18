#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUF_SIZE 1024

/* Function prototypes */
void error_exit(int code, const char *msg, ...);

/**
 * main - Copy content from one file to another
 *
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, or exit with an error code
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[BUF_SIZE];

	/* Check for correct number of arguments */
	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n");

	/* Open source file for reading */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	/* Open or create destination file for writing, truncate if exists */
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to %s\n", argv[2]);

	/* Copy content from source file to destination file */
	do {
		bytes_read = read(fd_from, buffer, BUF_SIZE);
		if (bytes_read == -1)
			error_exit(98, "Error: Can't read from file %s\n", argv[1]);

		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			error_exit(99, "Error: Can't write to %s\n", argv[2]);

	} while (bytes_read == BUF_SIZE);

	/* Close file descriptors */
	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_from);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_to);

	return (0);
}

/**
 * error_exit - Print an error message and exit with the specified code
 *
 * @code: Exit code
 * @msg: Error message format
 */
void error_exit(int code, const char *msg, ...)
{
	va_list args;

	va_start(args, msg);
	dprintf(STDERR_FILENO, msg, args);
	va_end(args);

	exit(code);
}

