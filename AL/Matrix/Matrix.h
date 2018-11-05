#ifndef HEADER_MATRIX
#define HEADER_MATRIX

#include <stdio.h>
#include "Row.h"

template <class T_>
class Matrix{
	friend class Row<T_>;

public:
	struct MatrixOperationException{
		enum struct ExceptionType{SUM_SIZE_MISMATCH, MUL_SIZE_MISMATCH, LINE_OUTOFBOUNDS, ROW_OUTOFBOUNDS, ROW_MUL_ZERO, DET_NONSQUARE, ID_NONSQUARE};
		MatrixOperationException(MatrixOperationException::ExceptionType et, const char* msg) : type(et), message(msg){}
		ExceptionType type;
		const char* message;
	};

	Matrix(unsigned h, unsigned w, T_* initVals = 0);
	Matrix(unsigned h, unsigned w, T_ (*f)(void*, unsigned, unsigned));
	Matrix(const Matrix& og);
	~Matrix();

	unsigned w, h;
	T_* matrix;

private:
	bool isAllocated;

public:
	bool isSquare();
	bool isLowerTriangular();
	bool isUpperTriangular();
	bool isDiagonal();
	bool isScalar();
	bool isIdentity();

	bool isInvertible(T_* = 0);

	bool isSymmetric();
	bool isSkewSymmetric();


	

	void print(unsigned char dp = 4);
	Matrix<T_>& makeIdentity();
	Matrix<T_>* pullTranspose(Matrix<T_>* transpo);
	
	Matrix<T_> T();
	T_ det();

	Matrix<T_>& operator+=(Matrix<T_>);
	Matrix<T_>& operator*=(T_);
	Matrix<T_>& operator=(Matrix<T_>);
	Matrix<T_> operator+(Matrix<T_>);
	Matrix<T_> operator*(Matrix<T_>);
	Matrix<T_> operator*(T_);
	T_& operator()(unsigned, unsigned);
	Row<T_> operator()(unsigned);
	bool operator==(Matrix<T_>&);
};

////////////////////////
#include "Matrix.tcpp"//
////////////////////////

#endif