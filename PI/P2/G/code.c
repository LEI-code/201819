#include <stdio.h>
#include <math.h>


double sum_powers_from(double x, double y, int n){
	double res = 0;
	while(n>0)res += pow(x+((double)(--n)), y);
	return res;
}

double sum_inverses(int n){
	return sum_powers_from(1, -1, n);
	/*double res = 0;
	while(res += pow(n--, -1), n);
	return res;*/
}

int main(int argc, char const *argv[]){
	unsigned val = 0;
	while(scanf("%u", &val) != EOF)
		printf("%f\n", sum_inverses(val));
	return 0;
}