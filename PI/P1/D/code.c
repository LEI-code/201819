#include <stdio.h>

//never gonna be negative
unsigned sqr(int val){
	return val*val;
}

unsigned sum_squares_fromto(int beg, int end){
	unsigned res = 0;
	while(res += sqr(beg),beg++ != end);
	return res;
}

int main(int argc, char const *argv[]){
	int beg = 0, end = 0;
	scanf("%i %i", &beg, &end);
	printf("%u\n", sum_squares_fromto(beg, end));	
	return 0;
}