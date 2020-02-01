#include "Vector.h"

#pragma once
class Matrix {
public:
	Matrix(int n);
	Matrix(int n, double* dat);
	Matrix(const Matrix* A);
	void init(double* in);
	void set(double in, int i, int j);
	int  getn() { return n; }
	void setCol(Vector& col, int k);
	Vector getRow(int r);
	void print();

	Vector& operator[](int i);
	Matrix operator-(); // negation
	Matrix& operator=(const Matrix& rhs);

	// M, M -> M
	Matrix& operator+=(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);
	Matrix& operator*=(const Matrix& rhs);
	Matrix  operator+ (const Matrix& rhs);
	Matrix  operator- (const Matrix& rhs);
	Matrix  operator* (const Matrix& rhs);

	// MV -> V
	Vector  operator* (Vector& rhs);

	// M, T -> M
	Matrix& operator*=(const double& rhs);
	Matrix  operator* (const double& rhs);

	Matrix transpose();
	Matrix getDiag();
	Matrix getLower();
	Matrix getUpper();
	Matrix invDiag();



private:
	int n;
	double* dat;
};

Vector operator*(Vector& lhs, const Matrix& rhs);
Matrix operator*(const double& lhs, const Matrix& rhs);