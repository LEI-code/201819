#include <stdio.h>

double sum_positive_integers(int n){
	double res = 0;
	while(n>0){res += --n;}
	return res;
}

double sum_multiples(double num, int multiplier){
	return sum_positive_integers(multiplier)*num;
}

double sum_progression(double x0, double r, int n){
	return x0*n + sum_multiples(r, n);
	/*int res = 0;
	while(n>0)res += x0 + (r * (--n));
	return res;*/
}


int main(int argc, char const *argv[]){
	double x0 = 0, r = 0; int n = 0;
	while(scanf("%lf %lf %i", &x0, &r, &n) != EOF)
		printf("%f\n", sum_progression(x0, r, n));
	return 0;
}