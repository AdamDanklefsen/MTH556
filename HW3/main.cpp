#include "Common.h"
#pragma comment(lib, "LIB")
#include "Vector.h"
#include "Matrix.h"
#include "Lib_Linear.h"
#include "Lib_nLinear.h"
#include <iostream>
#include <iomanip>
//#include "Matlab.h"

long double f (long double x) { return  std::exp(-x) - x; }
long double fp(long double x) { return -std::exp(-x) - 1;     }


int main() {
	double bb[] = { 2, 4, 10 };	Vector b = Vector(3, bb);
	double AA[] = { 4,-1,0,-1,4,-1,0,-1,4 }; Matrix A = Matrix(3, AA);
	Vector X0 = Vector(3); X0.zero();

	auto CGM = ConjGradMethod(A, b, X0, 3);
	std::cout << "Conjugate Gradient Method converged to X* = " << (CGM.ans).str() << " in " << (CGM.errvec).size() << " steps\n";
	stdVectoCSV1D(CGM.errvec, "CGM.csv");

	auto NM = NewtonsMethod(f, fp, 5.25, 1e-14, 100);
	std::cout << "Newton's Method converged to x = " << std::setprecision(33) << NM.ans.at(NM.ans.size()-1) << " in " << (NM.errvec).size() << " steps\n";
	stdVectoCSV1D(NM.errvec, "NM.csv");

}