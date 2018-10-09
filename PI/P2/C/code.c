#include <stdio.h>

int sum_positive_integers(int n){
	int res = 0;
	while(n>0){res += --n;}
	return res;
}

int sum_multiples(int num, int multiplier){
	return sum_positive_integers(multiplier)*num;
}

int sum_progression(int x0, int r, int n){
	return x0*n + sum_multiples(r, n);
	/*int res = 0;
	while(n>0)res += x0 + (r * (--n));
	return res;*/
}

int sum_progression_recursive(int x0, int r, int n){
	return n>0 ? x0 + r*(n-1) + sum_progression_recursive(x0, r, n-1) : 0;
}

int main(int argc, char const *argv[]){
	int x0 = 0, r = 0, n = 0;
	while(scanf("%i %i %i", &x0, &r, &n) != EOF)
		printf("%i\n", sum_progression(x0, r, n));
	return 0;
}