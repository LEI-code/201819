#include <stdio.h>

double sum_progression(double x0, double r, int n){
	double res = 0;
	while(res += x0 + (r * (--n)), n-1);
	return res;
}

double sum_progression_recursive(double x0, double r, int n){
	return n-1 ? x0 + r*(n-1) + sum_progression_recursive(x0, r, n-1) : 0;
}

int main(int argc, char const *argv[]){
	double x0 = 0, r = 0, n = 0;
	scanf("%lf %lf %lf", &x0, &r, &n);
	printf("%f\n", sum_progression_recursive(x0, r, n));
	return 0;
}