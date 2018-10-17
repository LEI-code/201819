#include <stdio.h>

unsigned GetBlue(unsigned W, unsigned H){

	//----------------------_____----------------------------____-------------
	unsigned verticalBlues = 0;							//LOOP v
	/*for (int i = H; i > 1; i-=2){						
		verticalBlues += i;
	}*/
	unsigned n = (unsigned)((float)H/2.f+0.5f)-H%2;
	unsigned d = 2;
	unsigned a = H%2?3:2;
	verticalBlues = (n*(a*2+(n-1)*d))/2;				//< ARITHMETIC PROGRESSION
	//----------------------_____----------------------------____-------------
	unsigned horizontalBlues = H%2 - 1;					//LOOP v
	/*for (unsigned i = 0, add = W; i < (unsigned)((float)H/2.f+0.5f); ++i, add-=2){
		horizontalBlues+=add;
	}*/
	d = 2;
	n = (unsigned)((float)H/2.f+0.5f);
	a = W-2*(n-1);
	horizontalBlues += (n*(a*2+(n-1)*d))/2;				//< ARITHMETIC PROGRESSION
	//----------------------_____----------------------------____-------------

	return verticalBlues+horizontalBlues;
}

int main(int argc, char const *argv[]){
	unsigned W = 0, H = 0;
	while(scanf("%u%u", &W, &H) != EOF){
		unsigned B = GetBlue(W, H), Y = W*H-B;
		printf("%u %u\n", B, Y);
	}
	return 0;
}