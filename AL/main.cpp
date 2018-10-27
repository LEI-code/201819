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

unsigned m1[2][3] = {
	{2, 3, 4},
	{1, 0, 0}
};
unsigned m2[3][2] = {
	{0, 1000},
	{1, 100},
	{0, 10}
};

int main(int argc, char const *argv[]){
	try{
		int(*lelambda)(Matrix<int>& m, unsigned j, unsigned i) = [](Matrix<int>& m, unsigned j, unsigned i) -> int {return 0;};

		puts("\n\nA----------------");
		Matrix<int> n1 = Matrix<int>( 6, 4, lelambda = [](Matrix<int>& m, unsigned j, unsigned i) -> int {
			return i+j;
		});
		n1.print(0); n1.~Matrix<int>();

		puts("\n\nB----------------");
		n1 = Matrix<int>( 3, 5, lelambda = [](Matrix<int>& m, unsigned j, unsigned i) -> int {
			return 2*i*i-3*j;
		});
		n1.print(0); n1.~Matrix<int>();

		puts("\n\nC----------------");
		n1 = Matrix<int>( 4, 3, lelambda = [](Matrix<int>& m, unsigned j, unsigned i) -> int {
			return i+j>3?1:i+j==3?2:3;
		});
		n1.print(0); n1.~Matrix<int>();

		puts("\n\nD----------------");
		n1 = Matrix<int>( 3, 3, lelambda = [](Matrix<int>& m, unsigned j, unsigned i) -> int {
			return i+j==4?3:!((i+j)%3)?-1:0;
		});
		n1.print(0); n1.~Matrix<int>();

		puts("\n\nE----------------");
		n1 = Matrix<int>( 4, 5, lelambda = [](Matrix<int>& m, unsigned j, unsigned i) -> int {
			return i==1?j:2*lelambda(m, i-1,j);
		});
		n1.print(0); n1.~Matrix<int>();

		puts("\n\nF----------------");
		n1 = Matrix<int>( 3, 4, lelambda = [](Matrix<int>& m, unsigned j, unsigned i) -> int {
			return i==1?(((int)pow(-1, i+j+1))*(2*i - j)):-lelambda(m, i-1,j)+1;
		});
		n1.print(0); n1.~Matrix<int>();

		puts("\n\nG----------------");
		n1 = Matrix<int>( 4, 3, lelambda = [](Matrix<int>& m, unsigned j, unsigned i) -> int {
			return i==1?j:((int)pow(-1, i+j))*2*lelambda(m, i-1, j);
		});
		n1.print(0); n1.~Matrix<int>();		
	}catch(Matrix<unsigned>::MatrixOperationException e){
		puts(e.message);
	}
	return 0;
}