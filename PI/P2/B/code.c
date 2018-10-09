#include <stdio.h>

int sum_positive_integers(int n){
	int res = 0;
	while(n>0){res += --n;}
	return res;
}

int sum_multiples(int num, int multiplier){
	return sum_positive_integers(multiplier)*num;
	/*int res = 0; 
	while(res += (multiplier--) * num, multiplier>=0);
	return res;*/
}

/*int sum_multiples_recursive(int num, int multiplier){
	return multiplier>=0 ? num*multiplier + sum_multiples_recursive(num, multiplier-1) : 0;
}*/

int main(int argc, char const *argv[]){
	int val = 0, mult = 0;
	while(scanf("%i %i", &val, &mult) != EOF)
		printf("%i\n", sum_multiples(val, mult));
	return 0;
}