#include <stdio.h>
#include <math.h>

double sum_powers_from(double x, double y, int n){
	double res = 0;
	while(n>0)res += pow(x+((double)(--n)), y);
	return res;
}

double sum_inverse_squares(int n){
	return sum_powers_from(1, -2, n);
}

int main(int argc, char const *argv[]){
	int val = 0;
	while(scanf("%i", &val) != EOF)
		printf("%f\n", sum_inverse_squares(val));
	return 0;
}