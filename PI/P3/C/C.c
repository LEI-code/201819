#include <stdio.h>

int blue(int w, int h){
	unsigned extra, smallest, greatest;
	unsigned a, n, d;

	if(w<h){smallest = w; greatest = h;}
	else   {smallest = h; greatest = w;}
	extra = greatest - smallest;

	a = 1;
	n = smallest/2+smallest%2;
	d = 4;
	return 
			(n*(a*2+(n-1)*d))/2									//arithmetic progression
		+	smallest * (extra/2 + (!(smallest%2) && extra%2));	//left overs (not part of the square)
}

int yllw(int w, int h){
	return w*h - blue(w, h);
}

int main(int argc, char const *argv[]){
	int w, h;
	while(scanf("%d%d", &w, &h) != EOF)
		printf("%d %d\n", blue(w, h), yllw(w, h));
	return 0;
}