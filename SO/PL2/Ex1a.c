#include <stdio.h>
#include <stdlib.h>
int main() {
	int p1, p2;
	p1 = fork();
	p2 = fork();
	printf("aye\n");
	exit(0);
} 