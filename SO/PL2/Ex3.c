#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wait.h>

#define piperead  0
#define pipewrite 1
int pipeChildWrite[2] = {0};
int pipeParntWrite[2] = {0};

int branchout(void(*child)()){
	int c = fork();if(!c)child();return c;
}

void child_proc(){
	close(pipeChildWrite[piperead]);
	close(pipeParntWrite[pipewrite]);
	
	void kbInterruptHandlerChild(int dummy){}
	signal(SIGINT, kbInterruptHandlerChild);

	char currProcessing = 0;
	while(read(pipeParntWrite[piperead], &currProcessing, 1), currProcessing != '\n'){
		if     (currProcessing <= 'z' && currProcessing >= 'a')currProcessing -= 'a'-'A';
		else if(currProcessing <= 'Z' && currProcessing >= 'A')currProcessing += 'a'-'A';
		write(pipeChildWrite[pipewrite], &currProcessing, 1);
	}
	close(pipeChildWrite[pipewrite]);
	close(pipeParntWrite[piperead]);
	//puts("deadkid");
	return;
}

void endIt(){
	write(pipeParntWrite[pipewrite], "\n", 1); //this signals the child to kill itself
	wait(0);
	close(pipeParntWrite[pipewrite]);
	close(pipeChildWrite[piperead]);
	//puts("dead dad");
}

int main(int argc, char const *argv[]){
	pipe(pipeParntWrite);
	pipe(pipeChildWrite);

	if(!branchout(child_proc))return 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////PARENT////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	close(pipeParntWrite[piperead]);
	close(pipeChildWrite[pipewrite]);

	void kbInterruptHandlerParent(int dummy){endIt(); exit(0);}
	signal(SIGINT, kbInterruptHandlerParent);

	char buffer[2000] = {0}; int bufferlen = 0;
	for (;fgets(buffer, 2000, stdin);){
		bufferlen = strlen(buffer);
		buffer[--bufferlen] = '\0';	//remove \n at the end

		write(pipeParntWrite[pipewrite], buffer, bufferlen);

		for (int i = 0; i < bufferlen; ++i){
			read (pipeChildWrite[piperead],  &buffer[i], 1);
		}

		puts(buffer);
	}

	endIt();
	
	return 0;
}