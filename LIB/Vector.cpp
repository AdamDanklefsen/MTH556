#include "Vector.h"
#include <iostream>

Vector::Vector(int n) :
	n(n),
	dat(new double[n]) {}
Vector::Vector(int n, double* dat) :
	n(n),
	dat(new double[n]) {
	for (int i = 0; i < n; i++) {
		this->dat[i] = dat[i];
	}
	}

Vector::Vector(const Vector* a) :
	n(a->n),
	dat(new double[n]) {
	for (int i = 0; i < n; i++) {
		dat[i] = a->dat[i];
	}
}

void Vector::init(double* in) {
	for (int i = 0; i < n; i++) {
		dat[i] = in[i];
	}
}
void Vector::set(double in, int i) {
	dat[i] = in;
}
void Vector::zero() {
	for (int i = 0; i < n; i++) {
		dat[i] = 0;
	}
}
void Vector::print() const {
	for (int i = 0; i < n; i++) {
		std::cout << dat[i] << "\t";
	}
	//std::cout << std::endl;
}

std::string Vector::str() const {
	using namespace std;
	string ret;
	for (int i = 0; i < n-1; i++) {
		ret += to_string(dat[i]) + "\t";
	}
	ret += to_string(dat[n - 1]);
	return ret;
}

Vector& Vector::getBasis(int n, int k) {
	double* b = new double[n];
	for (int i = 0; i < n; i++) {
		b[i] = 0;
	}b[k] = 1;
	return *(new Vector(n,b));
}

double& Vector::operator[](int i) {
	return dat[i];
}
Vector Vector::operator-() {
	double* b = new double[n];
	for (int i = 0; i < n; i++) {
		b[i] = -dat[i];
	}
	return Vector(n,b);
}

Vector& Vector::operator=(const Vector rhs) {
	for (int i = 0; i < n; i++) {
		//print(); std::cout << "\t"; rhs.print(); std::cout << std::endl;
		dat[i] = rhs.dat[i];
	}
	return *this;
}
Vector& Vector::operator+=(const Vector& rhs) {
	for (int i = 0; i < n; i++) {
		dat[i] += rhs.dat[i];
	}
	return *this;
}
Vector& Vector::operator-=(const Vector& rhs) {
	for (int i = 0; i < n; i++) {
		dat[i] -= rhs.dat[i];
	}
	return *this;
}
Vector Vector::operator+(const Vector& rhs) const {
	double* b = new double[n];
	for (int i = 0; i < n; i++) {
		b[i] = dat[i] + rhs.dat[i];
	}
	return Vector(n, b);
}
Vector Vector::operator-(const Vector& rhs) const {
	double* b = new double[n];
	for (int i = 0; i < n; i++) {
		b[i] = dat[i] - rhs.dat[i];
	}
	return Vector(n,b);
}

Vector& Vector::operator*=(const double& rhs) {
	for (int i = 0; i < n; i++) {
		dat[i] *= rhs;
	}
	return *this;
}
Vector Vector::operator*(const double& rhs) {
	return Vector(*this) *= rhs;
}

double Vector::operator*(const Vector& rhs) {
	double ret = 0;
	for (int i = 0; i < n; i++) {
		ret += dat[i] * rhs.dat[i];
	}
	return ret;
}

double Vector::norm() {
	return std::sqrt(*this * *this);
}

Vector operator*(const double& lhs, const Vector& rhs) {
	return Vector(rhs) *= lhs;
}
