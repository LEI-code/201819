#include <stdio.h>
#include <math.h>

double toMetric(int feet, int inches){
	return (feet*12+inches)*2.54/100;
}

int main(int argc, char const *argv[]){
	int feet, inches;
	while(scanf("%d%d", &feet, &inches)!=EOF)
		//no need to round as there's never more than 2 dec places
		printf("%f\n", round(toMetric(feet, inches)*100)/100);

	return 0;
}