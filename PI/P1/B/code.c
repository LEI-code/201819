/*------------------------------------------------------------- M A T R I X -------------------------------------------------------------*/
#include <stdio.h>

/*int main(int argc, char const *argv[]){
	unsigned val = 0, multiplied = 0, prev_multiplied = 0, multiplier = 1;

	scanf("%u", &val);	//read

	if(!val){puts("inf"); return 0;}

	//runs maximum 0x100000000 times
	for(//starts with *2
		prev_multiplied = val, multiplied = val<<1;
		//while the previous is smaller (if not means it overflowed)
		prev_multiplied < multiplied;
		//get next value, store old, increase multiplier
		prev_multiplied = multiplied, multiplied += val, multiplier++
	);	//loop needn't have body

	printf("%u\n", multiplier);
	return 0;
}*/

/*int main(int argc, char const *argv[]){
	unsigned 
		val = 0
	;

	scanf("%u", &val);	//read

	if(!val){puts("inf"); return 0;}

	//does not work because of sfp(single floating point) precision
	//mantissa is 23 bits, which means the range of accurately 
	//representable integers is 2^23-1 negative to positive
	float max = 0xFFFFFFFF;

	printf("%.0f\n", max / val);

	return 0;
}*/

int main(int argc, char const *argv[]){
	
	unsigned 
		val = 0
	;

	scanf("%u", &val);	//read

	if(!val){puts("inf"); return 0;}

	//simple but effective, we don't need decimal places
	//and integer arithmetic is just right for this
	printf("%u\n", 0xFFFFFFFF/val);

	return 0;
}


