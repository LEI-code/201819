#ifndef ROW_HEADER
#define ROW_HEADER

#include "Matrix.h"

template<class T> class Matrix;

template<class T>
class Row{
	unsigned w;
	T* 		 r;
	bool isAllocated;
public:
	Row(Matrix<T>* m, unsigned index);
	Row(const Row& oda);
	~Row();

	T& operator()(unsigned x);
	Row<T>& operator+=(Row x);	//ADD ROW
	Row<T>& operator*=(T x);	//MULT SCALAR
	Row<T>  operator*(T x);		//MULT SCALAR INST
	Row<T>& operator<<=(Row x);	//SWITCH
};

/////////////////////
#include "Row.tcpp"//
/////////////////////

#endif