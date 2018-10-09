#include <stdio.h>

double sqr(double val){
	return val*val;
}

double sum_squares_from(double x, double n){
	double res = 0;
	while(res += sqr(x+(--n)), n);
	return res;
}

double sum_squares_from_recursive(double x, double n){
	return n ? sqr(x+n-1) + sum_squares_from_recursive(x, n-1) : 0;
}

int main(int argc, char const *argv[]){
	double x = 0, n = 0;
	while(scanf("%lf %lf", &x, &n) != EOF)
		printf("%f\n", sum_squares_from_recursive(x, n));
	return 0;
}