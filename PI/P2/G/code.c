#include <stdio.h>
#include <math.h>

//sum_powers_from changed
double sum_inverses_spf(int n){
	double res = 0;
	while(res += pow(n--, -1), n);
	return res;
}

//sum_powers_from_recursive changed
double sum_inverses_recursive_spf(int n){ 
	return n ? pow(n, -1) + sum_inverses_recursive_spf(n-1) : 0;
}

//another more optimal way
double sum_inverses(unsigned n){
	double res = 0;
	while(res += 1./(double)n, --n);
	return res;
}

//another more optimal way
double sum_inverses_recursive(unsigned n){
	return n>0 ? 1./(double)n + sum_inverses_recursive(n-1) : 0;
}

int main(int argc, char const *argv[]){
	unsigned val = 0;
	while(scanf("%u", &val) != EOF)
		printf("%f\n", sum_inverses_spf(val));
	return 0;
}