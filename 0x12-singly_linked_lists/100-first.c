#include <stdio.h>

/* Function to print the specified message */
void before_main(void) __attribute__((constructor));

/**
 * before_main - Function to be executed before main.
 *               Prints the specified message.
 */
void before_main(void)
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}

/**
 * main - Main function.
 *
 * Return: Always 0.
 */
int main(void)
{
	return (0);
}

