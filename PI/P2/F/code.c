#include <stdio.h>
#include <math.h>

double sum_powers_from(double x, double y, int n){
	double res = 0;
	while(n>0)res += pow(x+((double)(--n)), y);
	return res;
}

int main(){
	double 	x = 0;
	double 	y = 0;
	int 	n = 0;
	while(scanf("%lf%lf%i", &x, &y, &n) != EOF)
		printf("%f\n", sum_powers_from(x, y, n));
	return 0;
}