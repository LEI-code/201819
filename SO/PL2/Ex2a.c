#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>

int branchout(void(*child)()){
	int c = fork();
	if(!c)child();
	return c;
}

void child_proc(){
	int ppid = getppid();
	for (int i = 0; i < 3; ++i)printf("Eu sou o filho, meu pai é %i\n", ppid);
	sleep(2);
}


int main(int argc, char const *argv[]){
	if(!branchout(child_proc))return 0;

	int p = getpid();
	for (int i = 0; i < 5; ++i)printf("Eu sou o pai, minha identificação é %i\n", p);
	wait(0);

	return 0;
}