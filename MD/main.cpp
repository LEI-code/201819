#include <stdio.h>
#include <stdlib.h>

#include "NumericalBase/NumericalBase.h"

int main(int argc, char const *argv[]){
	if(argc < 4){puts("need params"); return 0;}
	NumberValue(argv[1], strtol(argv[2], 0, 10)).print(strtol(argv[3], 0, 10));
	return 0;
}