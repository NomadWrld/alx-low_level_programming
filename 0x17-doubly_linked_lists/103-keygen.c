#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD_VALUE 4096

// Function to generate the key for a given username
unsigned int generate_key(const char *username) {
	unsigned int key = 0;

	// Iterate through each character of the username
	for (int i = 0; username[i] != '\0'; i++) {
		// Multiply the ASCII value of the character by its position in the username
		key += (unsigned int)(username[i]) * (i + 1);
	}

	// Take modulo 4096 of the running sum
	key %= MOD_VALUE;

	return key;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <username>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// Generate the key for the provided username
	unsigned int key = generate_key(argv[1]);

	// Print the generated key
	printf("%u\n", key);

	return (EXIT_SUCCESS);
}

