#include <stdio.h>

/* Function to check if a number is a palindrome */
int is_palindrome(int num) {
	int reversed = 0;
	int original = num;

	while (num > 0) {
		int digit = num % 10;
		reversed = reversed * 10 + digit;
		num /= 10;
	}

	return reversed == original;
}

int main(void) {
	int largest_palindrome = 0;
	int i, j;
	FILE *file;

	/* Find the largest palindrome made from the product of two 3-digit numbers */
	for (i = 100; i < 1000; i++) {
		for (j = 100; j < 1000; j++) {
			int product = i * j;
			if (is_palindrome(product) && product > largest_palindrome) {
				largest_palindrome = product;
			}
		}
	}

	/* Save the result in the file 102-result */
	file = fopen("102-result", "w");
	if (file != NULL) {
		fprintf(file, "%d", largest_palindrome);
		fclose(file);
	}

	return (0);
}

