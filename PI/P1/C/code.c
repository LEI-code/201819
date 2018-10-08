/*------------------------------------------------------------- M A T R I X -------------------------------------------------------------*/
#include <stdio.h>

int succ(int x){
	return x+1;
}

int pred(int x){
	return x-1;
}

int is_zero(int x){
	return x == 0;
}

int sum(int x, int y){
	return is_zero(y) ? x : sum(succ(x), pred(y));
}

int twice(int x){
    return sum(x, x);
}

int main(void){
	int x;
	scanf("%d", &x);
	int z = twice(x);
	printf("%d\n", z);
	return 0;
}