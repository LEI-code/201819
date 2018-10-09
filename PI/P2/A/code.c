#include <stdio.h>

unsigned sum_positive_integers(unsigned n){
	unsigned res = n;
	while(n--){res += n;}
	return res;
}

unsigned sum_positive_integers_recursive(unsigned n){
	return n ? n + sum_positive_integers_recursive(n-1) : 0;
}

int main(int argc, char const *argv[]){
	unsigned val = 0;
	while(scanf("%u", &val) != EOF)
		printf("%u\n", sum_positive_integers_recursive(val));
	return 0;
}