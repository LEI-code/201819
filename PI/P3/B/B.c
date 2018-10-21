#include <stdio.h>

//nr of goals                    1  2  3  4  5
//nr of backflips                1  2  3  2  1
//total of backflips             1  3  6  8  9

int backflipsPerGoalSet[6] = {0, 1, 3, 6, 8, 9};

int calcBackflips(int goals){
	return goals/5*9 + backflipsPerGoalSet[goals%5];
}

int main(int argc, char const *argv[]){
	int goals;
	while(scanf("%d", &goals) != EOF)
		printf("%d\n", calcBackflips(goals));
	return 0;
}
