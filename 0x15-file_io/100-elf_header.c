#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>
#include "main.h"

#define BUF_SIZE 1024

/**
 * print_type - Prints the type of the ELF header
 * @buf: Pointer to the buffer containing the ELF header
 */
void print_type(unsigned char *buf)
{
	const char *type;

	type = (buf[EI_TYPE] == ET_NONE ? "NONE (None)" :
			(buf[EI_TYPE] == ET_REL ? "REL (Relocatable file)" :
			 (buf[EI_TYPE] == ET_EXEC ? "EXEC (Executable file)" :
			  (buf[EI_TYPE] == ET_DYN ? "DYN (Shared object file)" :
			   (buf[EI_TYPE] == ET_CORE ? "CORE (Core file)" :
			    "Unknown")))));
	printf("  Type:                              %s\n", type);
}

/**
 * print_entry - Prints the entry point address of the ELF header
 * @buf: Pointer to the buffer containing the ELF header
 */
void print_entry(unsigned char *buf)
{
	unsigned int i;
	unsigned long int entry = 0;

	if (buf[EI_CLASS] == ELFCLASS32)
	{
		for (i = 0; i < 4; i++)
		{
			entry += buf[EI_ENTRY + i] << (i * 8);
		}
	}
	else if (buf[EI_CLASS] == ELFCLASS64)
	{
		for (i = 0; i < 8; i++)
		{
			entry += buf[EI_ENTRY + i] << (i * 8);
		}
	}
	printf("  Entry point address:               %#lx\n", entry);
}

/**
 * print_program_header_offset - Prints the program header offset
 * @buf: Pointer to the buffer containing the ELF header
 */
void print_program_header_offset(unsigned char *buf)
{
	unsigned int i;
	unsigned long int ph_offset = 0;

	if (buf[EI_CLASS] == ELFCLASS32)
	{
		for (i = 0; i < 4; i++)
		{
			ph_offset += buf[EI_PHOFF + i] << (i * 8);
		}
	}
	else if (buf[EI_CLASS] == ELFCLASS64)
	{
		for (i = 0; i < 8; i++)
		{
			ph_offset += buf[EI_PHOFF + i] << (i * 8);
		}
	}
	printf("  Program header offset:             %lu bytes\n", ph_offset);
}

/**
 * print_section_header_offset - Prints the section header offset
 * @buf: Pointer to the buffer containing the ELF header
 */
void print_section_header_offset(unsigned char *buf)
{
	unsigned int i;
	unsigned long int sh_offset = 0;

	if (buf[EI_CLASS] == ELFCLASS32)
	{
		for (i = 0; i < 4; i++)
		{
			sh_offset += buf[EI_SHOFF + i] << (i * 8);
		}
	}
	else if (buf[EI_CLASS] == ELFCLASS64)
	{
		for (i = 0; i < 8; i++)
		{
			sh_offset += buf[EI_SHOFF + i] << (i * 8);
		}
	}
	printf("  Section header offset:             %lu bytes\n", sh_offset);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	unsigned char buf[BUF_SIZE];
	ssize_t bytes_read = read(fd, buf, BUF_SIZE);

	if (bytes_read == -1)
	{
		perror("read");
		close(fd);
		exit(EXIT_FAILURE);
	}

	print_type(buf);
	print_entry(buf);
	print_program_header_offset(buf);
	print_section_header_offset(buf);

	close(fd);

	return (0);
}
