#include <stdio.h>

#define u_pe 0.3048
#define u_polegada (u_pe/12)
#define u_palmo 8.0*u_polegada
#define u_passo 5.0*u_pe
#define u_toesa 6.0*u_pe
#define u_covado 3.0*u_palmo
#define u_vara 5.0*u_palmo
#define u_braca 2.0*u_vara



double oldToNew(unsigned palmos, unsigned pes, unsigned passos, unsigned toesas, unsigned covados, unsigned varas, unsigned bracas, unsigned polegadas){
	return 
		palmos*u_palmo + 
		pes*u_pe + 
		passos*u_passo + 
		toesas*u_toesa + 
		covados*u_covado + 
		varas*u_vara + 
		bracas*u_braca + 
		polegadas*u_polegada;
}

int main(int argc, char const *argv[]){
	unsigned palmos, pes, passos, toesas, covados, varas, bracas, polegadas;
	while(scanf("%u%u%u%u%u%u%u%u", &palmos, &pes, &passos, &toesas, &covados, &varas, &bracas, &polegadas) != EOF)
		printf("%.4f\n", oldToNew(palmos, pes, passos, toesas, covados, varas, bracas, polegadas));
	return 0;
}