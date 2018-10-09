#include <stdio.h>

double sqr(double val){
	return val*val;
}

double sum_inverse_squares(unsigned n){
	double res = 0;
	while(res += 1./sqr(n), --n);
	return res;
}

double sum_inverse_squares_recursive(unsigned n){
	return n>0 ? 1./sqr(n) + sum_inverse_squares_recursive(n-1) : 0;
}

int main(int argc, char const *argv[]){
	unsigned val = 0;
	while(scanf("%u", &val) != EOF)
		printf("%f\n", sum_inverse_squares(val));
	return 0;
}