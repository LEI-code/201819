#include <stdio.h>

unsigned sum_multiples(unsigned num, unsigned multiplier){
	unsigned res = 0; 
	while(res += (multiplier--) * num, multiplier);
	return res;
}

unsigned sum_multiples_recursive(unsigned num, unsigned multiplier){
	return num ? num*multiplier + sum_positive_integers_recursive(num-1, multiplier) : 0;
}

int main(int argc, char const *argv[]){
	unsigned val = 0, mult = 0;
	while(scanf("%u %u", &val, &mult) != EOF)
		printf("%u\n", sum_multiples(val, mult));
	return 0;
}