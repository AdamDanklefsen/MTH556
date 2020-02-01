#include "Common.h"
#pragma comment(lib, "LIB")
#include "Vector.h"
#include "Matrix.h"
#include "Lib_Linear.h"
#include <iostream>


int main() {
	double bb[] = { 2, 4, 10 };	Vector b = Vector(3, bb);
	double AA[] = { 4,-1,0,-1,4,-1,0,-1,4 }; Matrix A = Matrix(3, AA);
	Vector X0 = Vector(3); X0.zero();
	double w = 2 / (1.f + std::sqrt(7.f / 8.f));

	auto jac = JacobiMethod(A, b, X0);
	std::cout << "Jacobi Method converged to X* = " << (jac.ans).str() << " in " << (jac.errvec).size() << " steps\n";
	
	auto gs = Gauss_SeidelMethod(A, b, X0);
	std::cout << "Gauss-Seidel Method converged to X* = " << (gs.ans).str() << " in " << (gs.errvec).size() << " steps\n";

	auto sor = SOR_Method(A, b, X0, w);
	std::cout << "SOR Method converged to X* = " << (sor.ans).str() << " in " << (sor.errvec).size() << " steps\n";

	system("pause");

	return 0;
}