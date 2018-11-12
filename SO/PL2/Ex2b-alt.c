#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>

int branchout(void(*child)()){
	int c = fork();
	if(!c)child();
	return c;
}

void grandchild_proc(){
	int ppid = getppid();
	printf("Eu sou o neto, meu pai é %i\n", ppid);
}

void child_proc_first(){
	printf("Eu sou o filho, eu sou %i, e meu pai é %i, e terei 2 filhos:\n", getpid(), getppid());
	if(!branchout(grandchild_proc))return;
	if(!branchout(grandchild_proc))return;
	wait(0);
}

void child_proc_latter(){
	printf("Eu sou o filho %i, meu pai é %i\n", getpid(), getppid());
}


int main(int argc, char const *argv[]){
	printf("Eu sou o pai, minha identificação é %i, terei 3 filhos e 2 netos:\n", getpid());
	if(!branchout(child_proc_first)) return 0;wait(0);
	if(!branchout(child_proc_latter))return 0;wait(0);
	if(!branchout(child_proc_latter))return 0;wait(0);

	return 0;
}