/*#include <stdio.h>

struct Stuff{
	Stuff(){valmate = 1;}
	Stuff(const Stuff& o){this->valmate = o.valmate;}
	~Stuff(){valmate = -1;}

	Stuff operator+(int x){
		Stuff nuobj = Stuff(*this); 
		nuobj.valmate += x;
		return nuobj;
	}

	int valmate = 0;
};

int main(int argc, char const *argv[]){
	Stuff yeet = Stuff();
	yeet.valmate = 2;
	Stuff sum = yeet + 419;
	printf("%d\n", sum.valmate);
	return 0;
}*/

/*#include <stdio.h>
//            y  x
unsigned arri[2][3] = {
	{1, 2, 3},
	{4, 5, 6}
};

int main(int argc, char const *argv[]){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 3; ++x){
			printf("%d ", arri[y][x]);
		}puts("\n\n");
	}
	puts("\n\n------------------------");
	for (int i = 0; i < 3*2; ++i){
		printf("%d ", ((unsigned*)arri)[i]);
	}puts("\n\n");
	return 0;
}*/





#include "Matrix/Matrix.h"
#include <stdio.h>

#define mt double

mt A[3][4] = {
	{3, 1,  0, -2},
	{1, 1, -1,  2},
	{0, 1,  1,  0}
};
mt B[3][4] = {
	{ 1, 0,  4,  2},
	{-1, 2, -1,  2},
	{ 2, 2,  1, -1}
};
mt C[3][4] = {
	{ 0,  0,  1, -2},
	{-2, -2, -1,  1},
	{ 2,  2,  1, -1}
};

#define a(y, x) ((mt(*)(void*, unsigned, unsigned))me)(me, x, y)

int main(int argc, char const *argv[]){
	try{
		/*puts("\n\nA----------------");
		Matrix<mt> n1 = Matrix<mt>( 6, 4, [](void* me, unsigned j, unsigned i) -> mt {
			return i+j;
		});
		n1.print(0); //n1.~Matrix<mt>();

		puts("\n\nB----------------");
		n1 = Matrix<mt>( 3, 5, [](void* me, unsigned j, unsigned i) -> mt {
			return (2*(i*i)) - (3*j);
		});
		n1.print(0); //n1.~Matrix<mt>();

		puts("\n\nC----------------");
		n1 = Matrix<mt>( 4, 3, [](void* me, unsigned j, unsigned i) -> mt {
			return i+j>3?1:i+j==3?2:3;
		});
		n1.print(0); //n1.~Matrix<mt>();

		puts("\n\nD----------------");
		n1 = Matrix<mt>( 3, 3, [](void* me, unsigned j, unsigned i) -> mt {
			return i+j==4?3:!((i+j)%3)?-1:0;
		});
		n1.print(0); //n1.~Matrix<mt>();

		puts("\n\nE----------------");
		n1 = Matrix<mt>( 4, 5, [](void* me, unsigned j, unsigned i) -> mt {
			return i==1?j:2*a(i-1,j);
		});
		n1.print(0); //n1.~Matrix<mt>();

		puts("\n\nF----------------");
		n1 = Matrix<mt>( 3, 4, [](void* me, unsigned j, unsigned i) -> mt {
			return i==1?(((mt)pow(-1, i+j+1))*(2*i - j)):-a(i-1,j)+1;
		});
		n1.print(0); //n1.~Matrix<mt>();

		puts("\n\nG----------------");
		n1 = Matrix<mt>( 4, 3, [](void* me, unsigned j, unsigned i) -> mt {
			return i==1?j:((mt)pow(-1, i+j))*2*a(i-1, j);
		});
		n1.print(0); n1.~Matrix<mt>();*/

		mt temp[4][4] = {
			{1, 2, 3, 3},
			{5, 10, 1, 2},
			{3, 6, 2, 4},
			{2, 4, 3, 2},
		};
		
		Matrix<mt> matt = Matrix<mt>(4, 4, (mt*)temp);
		matt(2) += matt(4)*(-5);
		printf("%i\n", matt.isInvertible());
	}catch(Matrix<mt>::MatrixOperationException e){
		puts(e.message);
	}
	return 0;
}