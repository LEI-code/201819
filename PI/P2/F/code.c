#include <stdio.h>
#include <math.h>

double sum_powers_from(double x, double n, double y){
	double res = 0;
	while(res += pow(x+(--n), y), n);
	return res;
}

double sum_powers_from_recursive(double x, double n, double y){
	return n ? pow(x+n-1, y) + sum_powers_from_recursive(x, n-1, y) : 0;
}

int main(int argc, char const *argv[]){
	double x = 0, n = 0, y = 0;
	scanf("%lf %lf %lf", &x, &n, &y);
	printf("%f\n", sum_powers_from(x, n, y));
	return 0;
}