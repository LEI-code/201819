#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 5;
	if(fork()){ 
		wait();
		printf("Valor de a = %d\n",a);
		printf(" a = %p\n",&a);
	}else{ 
		a = 10;
		printf("Valor de a = %d\n",a);
		printf(" a = %p\n",&a);
	}
	exit(0); 
} 