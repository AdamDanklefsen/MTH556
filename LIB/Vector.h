#pragma once
#include <iostream>
#include <string>

class Vector {
public:
	Vector(int n);
	Vector(int n, double* dat);
	Vector(const Vector* a);
	void init(double* in);
	void set(double in, int i);
	int  getn() { return n; }
	double* getdat() { return dat; }
	void zero();
	void print() const;
	std::string str() const;
	void printaddr() { std::cout << dat << std::endl; }
	static Vector& getBasis(int n, int k);

	double& operator[](int i);
	Vector  operator-(); // negation
	Vector& operator=(const Vector rhs);

	// V, V -> V
	Vector& operator+=(const Vector& rhs);
	Vector& operator-=(const Vector& rhs);
	Vector  operator+ (const Vector& rhs) const;
	Vector  operator- (const Vector& rhs) const;

	// V, T -> V
	Vector& operator*=(const double& rhs);
	Vector  operator* (const double& rhs);

	// V, V -> T
	double  operator* (const Vector& rhs); // dot product

	double  norm();


private:
	int n;
	double* dat;
};

Vector operator*(const double& lhs, const Vector& rhs);