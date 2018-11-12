#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#include "NumericalBase/NumericalBase.h"

int main(int argc, char const *argv[]){/*
	if(argc < 4){puts("need params"); return 0;}
	NumberValue(argv[1], strtol(argv[2], 0, 10)).print(strtol(argv[3], 0, 10));
	return 0;*/

	
	//PARAM 1: base 10 fraction to convert to base x
	//PARAM 2: base to convert to (x refered here  ^) (defaults to 2)
	//PARAM 3: precision in decimal places (defaults to 10)
	

	double base10nr = 0;
	int baseX = 2;
	int precision = 10;
	char* baseXnr = 0;

	if(argc-1 < 1){
		printf("nigger give arguments\n");
		return 1;
	}

	if(*(unsigned short*)argv[1] != *(unsigned short*)"0."){
		printf("nigger. Provide decimal shit nigger.\n");
		return 1;
	}

	base10nr = atof(argv[1]);
	if(argc-1 > 1)baseX = atoi(argv[2]);
	if(argc-1 > 2)precision = atoi(argv[3]);

	baseXnr = (char*)malloc(2+precision+1);
	*(unsigned short*)baseXnr = *(unsigned short*)"0.";	//overriding any of these
	baseXnr[precision] = '\0';							//two will get me fucked

	baseXnr+=2;											//skip the "0."
	unsigned currpos = 0;
	for (int i = 1; i < precision; ++i){
		double currPow = pow(baseX, -i);
		double currentRatio = base10nr/currPow;			//see if it fits
		if(currentRatio == 1){							//if fits perfectly
			baseXnr[currpos++] = '1';					//set current to one
			baseXnr[currpos] = '\0';					//null terminate it
			break;										//stop
		}else if(currentRatio < 1){						//if doesn't fit
			baseXnr[currpos++] = '0';					//just do zero
		}else{
			baseXnr[currpos++] = '0'+(int)currentRatio;
			base10nr -= currPow * trunc(currentRatio);
		}
	}
	baseXnr-=2;											//restore string

	printf("%s\n", baseXnr);
}