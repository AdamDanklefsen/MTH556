#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int n) :
	n(n),
	dat(new double[n*n]) {}

Matrix::Matrix(int n, double* dat) :
	n(n),
	dat(dat) {}

Matrix::Matrix(const Matrix* A) :
	n(A->n),
	dat(new double[n*n]) {
	for (int i = 0; i < n * n; i++) {
		dat[i] = A->dat[i];
	}
}

void Matrix::init(double* in) {
	for (int i = 0; i < n*n; i++) {
		dat[i] = in[i];
	}
}
void Matrix::set(double in, int i, int j) {
	dat[n * i + j] = in;
}
void Matrix::setCol(Vector& col, int k) {
	for (int i = 0; i < n; i++) {
		set(col.getdat()[i], i, k);
	}
}
Vector Matrix::getRow(int r) {
	double* b = new double[n];
	for (int i = 0; i < n; i++) {
		b[i] = dat[n * r + i];
	}
	return Vector(n,b);
}
void Matrix::print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << dat[n * i + j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Vector& Matrix::operator[](int i) {
	Vector a(n);
	double* b = new double[n];
	for (int j = 0; j < n; j++) {
		b[j] = dat[i * n + j];
	}
	a.init(b);
	return a;
}

Matrix Matrix::operator-() {
	double* b = new double[n * n];
	for (int i = 0; i < n * n; i++) {
		b[i] = -dat[i];
	}
	return Matrix(n, b);
}

Matrix& Matrix::operator=(const Matrix& rhs) {
	for (int i = 0; i < n*n; i++) {
		dat[i] = rhs.dat[i];
	}
	return *this;
}
Matrix& Matrix::operator+=(const Matrix& rhs) {
	for (int i = 0; i < n*n; i++) {
		dat[i] += rhs.dat[i];
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& rhs) {
	for (int i = 0; i < n*n; i++) {
		dat[i] -= rhs.dat[i];
	}
	return *this;
}
Matrix& Matrix::operator*=(const Matrix& rhs) {
	double* b = new double[n * n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[n * i + j] = 0;
			for (int k = 0; k < n; k++) {
				b[n * i + j] += dat[i * n + k] * rhs.dat[k * n + j];
			}
		}
	}
	dat = b;
	return *this;
}

Matrix Matrix::operator+(const Matrix& rhs) {
	double* b = new double[n * n];
	for (int i = 0; i < n*n; i++) {
		b[i] = dat[i] + rhs.dat[i];
	}
	return Matrix(n, b);
}
Matrix Matrix::operator-(const Matrix& rhs) {
	double* b = new double[n * n];
	for (int i = 0; i < n*n; i++) {
		b[i] = dat[i] - rhs.dat[i];
	}
	return Matrix(n, b);
}
Matrix Matrix::operator*(const Matrix& rhs) {
	return Matrix(*this) *= rhs;
}

Vector Matrix::operator*(Vector& rhs) {
	double* b = new double[n];
	for (int i = 0; i < n; i++) {
		b[i] = this->getRow(i) * rhs;
	}
	return Vector(n,b);
}

Matrix& Matrix::operator*=(const double& rhs) {
	for (int i = 0; i < n * n; i++) {
		dat[i] *= rhs;
	}
	return *this;
}
Matrix Matrix::operator*(const double& rhs) {
	double* b = new double[n * n];
	for (int i = 0; i < n * n; i++) {
		b[i] = dat[i] * rhs;
	}
	return Matrix(n, b);
}

Matrix Matrix::transpose() {
	double* b = new double[n * n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i * n + j] = dat[j * n + i];
		}
	}
	return Matrix(n,b);
}

Matrix Matrix::getDiag() {
	double* b = new double[n * n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i * n + j] = (i == j) * dat[i * n + j];
		}
	}
	return Matrix(n,b);
}

Matrix Matrix::getLower() {
	double* b = new double[n * n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i * n + j] = (j > i) * dat[i * n + j];
		}
	}
	return Matrix(n, b);
}

Matrix Matrix::getUpper() {
	double* b = new double[n * n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i * n + j] = (i > j) * dat[i * n + j];
		}
	}
	return Matrix(n, b);
}

Matrix Matrix::invDiag() {
	double* b = new double[n * n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) { b[i * n + j] = 1 / dat[i * n + j]; }
			else { b[i * n + j] = 0; }
		}
	}
	return Matrix(n, b);
}

Vector operator*(Vector& lhs, const Matrix& rhs) {
	return Matrix(rhs).transpose()*lhs;
}

Matrix operator*(const double& lhs, const Matrix& rhs) {
	return Matrix(rhs) *= lhs;
}
