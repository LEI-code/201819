#include <stdio.h>

int points(int megoals, int yegoals){
	int mepoints = (megoals == yegoals)?1:((megoals > yegoals)?3:0);
	mepoints += (megoals>=3) + ((megoals-yegoals)>=2); 
	mepoints -= (mepoints>4);
	return mepoints;
}

int main(int argc, char const *argv[]){
	int megoals, yegoals;
	while(scanf("%d%d", &megoals, &yegoals) != EOF)printf("%d\n", points(megoals, yegoals));
	return 0;
}