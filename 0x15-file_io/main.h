#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/* Task 0: read_textfile */
ssize_t read_textfile(const char *filename, size_t letters);

/* Task 1: create_file */
int create_file(const char *filename, char *text_content);

/* Task 2: append_text_to_file */
int append_text_to_file(const char *filename, char *text_content);

/* Task 3: cp */
#define BUF_SIZE 1024

/* Task 100: elf_header */
void error_exit(char *msg);
void print_magic(unsigned char *buf);
void print_class(unsigned char *buf);
void print_data(unsigned char *buf);
void print_version(unsigned char *buf);

#endif /* MAIN_H */

