#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/* Prototype for read_textfile */
ssize_t read_textfile(const char *filename, size_t letters);

/* Prototype for create_file */
int create_file(const char *filename, char *text_content);

/* Prototype for append_text_to_file */
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */

