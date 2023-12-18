#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>

/**
 * print_elf_header - Print information from ELF header
 * @header: ELF header structure
 */
void print_elf_header(Elf64_Ehdr header)
{
	printf("ELF Header:\n");
	printf("  Magic:   %x %c %c %c\n",
			header.e_ident[EI_MAG0], header.e_ident[EI_MAG1],
			header.e_ident[EI_MAG2], header.e_ident[EI_MAG3]);
	printf("  Class:   ELF%d\n",
			header.e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
	printf("  Data:    %s\n",
			header.e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" : "unknown");
	printf("  Version: %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:  %s\n",
			header.e_ident[EI_OSABI] == ELFOSABI_SYSV ?
			"UNIX - System V" : "unknown");
	printf("  ABI Ver: %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:    %s (Executable file)\n",
			header.e_type == ET_EXEC ? "EXEC" : "unknown");
	printf("  Entry:   %#lx\n", (unsigned long)header.e_entry);
}

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		close(fd);
		exit(98);
	}

	print_elf_header(header);
	close(fd);
	return 0;
}

