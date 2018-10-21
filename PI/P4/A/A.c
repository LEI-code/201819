#include <stdio.h>
#include <math.h>

double calcEarnings(double baseSalary, unsigned shiftEndHR, unsigned shiftEndMIN){
	double fractionOfHour = 1.0/60.0*shiftEndMIN;
	double hoursWorked = fractionOfHour + shiftEndHR-18;

	if(hoursWorked > 2.0) return baseSalary*2 + (baseSalary*1.5)*(hoursWorked-2);
	else                  return baseSalary*hoursWorked;
}

int main(int argc, char const *argv[]){
	double baseSalary; int shiftEndHR, shiftEndMIN;
	while(scanf("%lf%d%d", &baseSalary, &shiftEndHR, &shiftEndMIN) != EOF)
		printf("%f\n", round(calcEarnings(baseSalary, shiftEndHR, shiftEndMIN)*100.0)/100.0);
	return 0;
}