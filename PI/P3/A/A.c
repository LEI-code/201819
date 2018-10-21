#include <stdio.h>

double toMetric(int feet, int inches){
	double res = (feet*12+inches)*2.54;
}

int main(int argc, char const *argv[]){
	int feet, inches;
	while(scanf("%d%d", &feet, &inches)!=EOF)
		//no need to round as there's never more than 2 dec places
		printf("%f\n", toMetric(feet, inches));

	return 0;
}