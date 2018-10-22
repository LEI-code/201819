#include <stdio.h>

//nr of goals                    1  2  3  4
//nr of backflips                1  2  3  2
//total of backflips             1  3  6  8

int backflipsPerGoalSet[5] = {0, 1, 3, 6, 8};

int calcBackflips(int goals){
	return goals/4*8 + backflipsPerGoalSet[goals%4];
}

int main(int argc, char const *argv[]){
	int goals;
	while(scanf("%d", &goals) != EOF)
		printf("%d\n", calcBackflips(goals));
	return 0;
}
