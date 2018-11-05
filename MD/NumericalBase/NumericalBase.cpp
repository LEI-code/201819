#include "NumericalBase.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>

double logbx(double base, double x){return log(x)/log(base);}

NumberValue::NumberValue(const char* str, unsigned base) : buffer(0){
	if(base < 2 || base > 64){puts("stupid kid 1");*(char*)0 = 0;}
	unsigned digits = strlen(str);
	if(!digits){puts("stupid kid 2");*(char*)0 = 0;}

	for(unsigned i = 1; i <= digits; ++i){
		char currDigit = str[digits-i];
		unsigned digitVal, digitMultiplier = (unsigned)pow(base, i-1);

		if(currDigit >= '0' && currDigit <= '9'){		digitVal = (currDigit - '0');
		}else if(currDigit >= 'A' && currDigit <= 'Z'){	digitVal = (currDigit - 'A' + 0xA);
		}else if(currDigit >= 'a' && currDigit <= 'z'){	digitVal = (currDigit - 'a' +  36);
		}else{puts("stupid kid 3"); *(char*)0 = 0;}
		if(digitVal >= base){puts("INVALID SHIT NIGGER");*(char*)0 = 0;}
		buffer += digitVal * digitMultiplier;
	}	
}

NumberValue::NumberValue(unsigned long long bs10nr){}

NumberValue::~NumberValue(){}

void NumberValue::print(unsigned base){
	unsigned digits = (unsigned)logbx(base, buffer) + 1;
	char* str = (char*)malloc(digits+1);
	for (unsigned i = 0; i < digits; ++i){
		unsigned digit = (unsigned)(buffer/(unsigned)pow(base, i)) % base;
		str[digits - i - 1] = (digit < 10)?digit+'0':((digit<36)?digit-10+'A':digit-36+'a');
	}str[digits] = 0;
	printf("%s\n", str);
	free(str);
}