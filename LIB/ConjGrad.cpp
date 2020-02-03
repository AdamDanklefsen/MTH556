#include "Lib_Linear.h"
#include <iostream>

VecVec ConjGradMethod(Matrix A, Vector b, Vector x0, int n, double tol) {
	Vector Xold = new Vector(x0);
	Vector Xnew = new Vector(x0);
	double err = 1;
	std::vector<double> errvec;
	int k = 0;

	Vector r = A * Xold - b;
	Vector d = -r;
	double Lambda = getLambda(A, b, d, Xold);
	Xnew = Xold + Lambda * d;
	double alpha;
	Xold = Xnew;
	err = (A * Xnew - b).norm();
	errvec.emplace_back(err);

	while (err > tol) {
		k++;
		r = A * Xold - b;
		alpha = getAlpha(A, b, d, Xold);
		d = -r + alpha * d;
		Lambda = getLambda(A, b, d, Xold);
		Xnew = Xold + Lambda * d;

		err = (A * Xnew - b).norm();
		Xold = Xnew;
		errvec.emplace_back(err);
	}


	return VecVec(Xnew, errvec);
}

double getLambda(Matrix A, Vector b, Vector d, Vector x) {
	Vector r = A * x - b;
	return -(d * r) / (d * A * d);
}

double getAlpha(Matrix A, Vector b, Vector d, Vector x) {
	Vector r = A * x - b;

	return (r * A * d) / (d * A * d);
}