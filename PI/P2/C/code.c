#include <stdio.h>

int sum_progression(int x0, int r, int n){
	int res = 0;
	while(res += x0 + (r * (--n)), n);
	return res;
}

int sum_progression_recursive(int x0, int r, int n){
	return n ? x0 + r*(n-1) + sum_progression_recursive(x0, r, n-1) : 0;
}

int main(int argc, char const *argv[]){
	int x0 = 0, r = 0, n = 0;
	scanf("%i %i %i", &x0, &r, &n);
	printf("%i\n", sum_progression(x0, r, n));
	return 0;
}