#ifndef ROW_HEADER
#define ROW_HEADER

#include "Matrix.h"

template<class T> class Matrix;

template<class T>
class Row{
	T* 		 r;
	unsigned w;
public:
	Row(Matrix<T>* m, unsigned index);

	T& operator()(unsigned x);
	Row<T>& operator+=(Row x);
	Row<T>& operator*=(T x);
	Row<T>& operator<<=(Row x);
};

/////////////////////
#include "Row.tcpp"//
/////////////////////

#endif