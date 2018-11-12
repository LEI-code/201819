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
	for (int i = 0; i < 3; ++i)printf("Eu sou o neto, meu pai é %i\n", ppid);
	sleep(2);
}

void child_proc_first(){
	if(!branchout(grandchild_proc))return;
	if(!branchout(grandchild_proc))return;
	int ppid = getppid();
	int pid = getpid();
	for (int i = 0; i < 3; ++i)printf("Eu sou o filho, eu sou %i, e meu pai é %i\n", pid, ppid);
	wait(0);
	sleep(2);
}

void child_proc_latter(){
	int ppid = getppid();
	for (int i = 0; i < 3; ++i)printf("Eu sou o filho, meu pai é %i\n", ppid);
	sleep(2);
}


int main(int argc, char const *argv[]){
	if(!branchout(child_proc_first)) return 0;
	if(!branchout(child_proc_latter))return 0;
	if(!branchout(child_proc_latter))return 0;

	int p = getpid();
	for (int i = 0; i < 5; ++i)printf("Eu sou o pai, minha identificação é %i\n", p);
	wait(0);

	return 0;
}