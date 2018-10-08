#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	int x, y;
} Px2_t;

double Px2_Dist(Px2_t a, Px2_t b){
	return sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
}

typedef struct{
	Px2_t pts[3];
} Tri_t;

int main(int argc, char const *argv[]){
	unsigned i = 0;
	double SideDistances[3] = {0};	/*Distances: a-b b-c c-a*/
	Tri_t GoldenTriangle;			/*Initial Triangle*/
	Tri_t HiddenTriangle;			/*Triangle We're Eventually Gnna Find*/
	unsigned PtAmt = 0;				/*Amount of Points*/
	Px2_t* PlanePts = 0;			/*Said Points*/
	char CurrSuccess = 0; 			/*Essentially a Latest Success "bool"*/

	scanf("%d %d %d %d %d %d %d", 	/*read golden triangle and amount of plane points*/
		&GoldenTriangle.pts[0].x, &GoldenTriangle.pts[0].y,
		&GoldenTriangle.pts[1].x, &GoldenTriangle.pts[1].y,
		&GoldenTriangle.pts[2].x, &GoldenTriangle.pts[2].y,
		&PtAmt
	);

	for (i = 0; i < 3; ++i) SideDistances[i] = Px2_Dist(GoldenTriangle.pts[i], GoldenTriangle.pts[(i+1)%3]);
	/*calculate distances between the golden triangle points*/

	if(PtAmt<4){
		puts("Less Than 4 Points");
		printf("input:\n %d %d\n%d %d\n%d %d\n%d\n", 
			GoldenTriangle.pts[0].x, GoldenTriangle.pts[0].y,
			GoldenTriangle.pts[1].x, GoldenTriangle.pts[1].y,
			GoldenTriangle.pts[2].x, GoldenTriangle.pts[2].y,
			PtAmt
			);
		return 0;
	}			/*not rly supposed to be < 4*/

	PlanePts = (Px2_t*)malloc(PtAmt*sizeof(Px2_t));	/*allocate space for other points*/
	for (i = 0; i < PtAmt; ++i) scanf("%d %d", &PlanePts[i].x, &PlanePts[i].y);
	/*read points*/ 

	unsigned f, s;
	for (f = 0; f < PtAmt; ++f){				/*find a -> b or vice versa*/
		for (s = f+1; s < PtAmt; ++s){
			if(Px2_Dist(PlanePts[f], PlanePts[s]) == SideDistances[0]){
				HiddenTriangle.pts[0] = PlanePts[f];
				HiddenTriangle.pts[1] = PlanePts[s];
				CurrSuccess = 1;
				goto FoundAB_Tag; /*basically break out of the nested */
			}					  /*loops without need for an extra condition*/
		}
	}FoundAB_Tag:

	if(!CurrSuccess){				/*no point found, we're in the shit now*/
		puts("Failed to find any points where the distance between them is a->b");
		printf("input:\n %d %d\n%d %d\n%d %d\n%d\n", 
			GoldenTriangle.pts[0].x, GoldenTriangle.pts[0].y,
			GoldenTriangle.pts[1].x, GoldenTriangle.pts[1].y,
			GoldenTriangle.pts[2].x, GoldenTriangle.pts[2].y,
			PtAmt
		);
		for (i = 0; i < PtAmt; ++i)printf("%d %d\n", PlanePts[i].x, PlanePts[i].y);
		free(PlanePts); return 0;	/*free and gtfo*/
	}CurrSuccess = 0;				/*reset this*/

	/*now we don't know whether which one of those 2 was a or b, so try and*/
	unsigned rtry;
	for (rtry = 0; rtry < 2; ++rtry){
		for (i = 0; i < PtAmt; ++i){				/*find a -> c*/
			if(	SideDistances[2] == Px2_Dist(HiddenTriangle.pts[0], PlanePts[i])
				&&											/*find b -> c*/
				SideDistances[1] == Px2_Dist(HiddenTriangle.pts[1], PlanePts[i])
			  ){
				HiddenTriangle.pts[2] = PlanePts[i];
				CurrSuccess = 1;
				goto FoundC_Tag;
			}
		}
		/*and if we couldn't find it, means we had a and b switched*/
		if(!CurrSuccess){
			Px2_t switcht = HiddenTriangle.pts[0];
			HiddenTriangle.pts[0] = HiddenTriangle.pts[1];
			HiddenTriangle.pts[1] = switcht;
		}
	}FoundC_Tag:

	if(!CurrSuccess){
		puts("failed to find a point where the distance to a/c is the same as the golden triangle"); 
		free(PlanePts); return 0;
	}

	int qsort_2dPt(Px2_t* a, Px2_t* b){	/*qsort order func*/
		if(a->x == b->x)return a->y - b->y;	/*if x is the same, order by y*/
		else 			return a->x - b->x;	/*otherwise order by x*/
	}

	qsort(HiddenTriangle.pts, 3, sizeof(Px2_t), (int (*)(const void*,const void*))qsort_2dPt);

	printf("%d %d\n%d %d\n%d %d\n", HiddenTriangle.pts[0].x, HiddenTriangle.pts[0].y, HiddenTriangle.pts[1].x, HiddenTriangle.pts[1].y, HiddenTriangle.pts[2].x, HiddenTriangle.pts[2].y);

	free(PlanePts); 
	return 0;
}