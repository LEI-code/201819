#ifndef HEADER_MATRIX
#define HEADER_MATRIX

#include <stdio.h>
#include "Row.h"

template <class T>
class Matrix{
	friend class Row<T>;

public:
	struct MatrixOperationException{
		enum struct ExceptionType{SUM_SIZE_MISMATCH, MUL_SIZE_MISMATCH, LINE_OUTOFBOUNDS, ROW_OUTOFBOUNDS, ROW_MUL_ZERO};
		MatrixOperationException(MatrixOperationException::ExceptionType et, const char* msg) : type(et), message(msg){}
		ExceptionType type;
		const char* message;
	};

	Matrix(unsigned h, unsigned w, T* initVals = 0);
	Matrix(unsigned h, unsigned w, T (*f)(Matrix<T>&, unsigned, unsigned));
	Matrix(const Matrix& og);
	~Matrix();


	unsigned w, h;
	T* matrix;

private:
	bool isAllocated;

public:
	bool isSquare();
	bool isLowerTriangular();
	bool isUpperTriangular();
	bool isDiagonal();
	bool isScalar();
	bool isIdentity();

	bool isSymmetric();
	bool isSkewSymmetric();

	void print(unsigned char dp = 4);
	Matrix<T>* pullIdentity(Matrix<T>* initVals);
	Matrix<T>* pullTranspose(Matrix<T>* transpo);

	Matrix<T>& operator+=(Matrix<T>);
	Matrix<T>& operator*=(T);
	Matrix<T> operator+(Matrix<T>);
	Matrix<T> operator*(Matrix<T>);
	Matrix<T> operator*(T);
	T& operator()(unsigned, unsigned);
	Row<T> operator()(unsigned);
	bool operator==(Matrix<T>&);
};

////////////////////////
#include "Matrix.tcpp"//
////////////////////////

#endif