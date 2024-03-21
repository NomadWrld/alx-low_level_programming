#include <stdio.h>
#include <stdlib.h>

/* Function to generate the key for a given username */
unsigned int generate_key(char *username) {
	unsigned int key = 0;
	int i;

	for (i = 0; username[i] != '\0'; i++) {
		key += username[i];
	}

	return key;
}

int main(int argc, char *argv[]) {
	unsigned int key;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return EXIT_FAILURE;
	}

	/* Generate the key for the provided username */
	key = generate_key(argv[1]);
	printf("%u\n", key);

	return (EXIT_SUCCESS);
}
