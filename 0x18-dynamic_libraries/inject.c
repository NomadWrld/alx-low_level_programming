#define _GNU_SOURCE
#include <stdio.h>

void __attribute__((constructor)) init(void) {
	printf("--> Please make me win!\n");
}
