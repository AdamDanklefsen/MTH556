#include "Lib_Linear.h"
#include <iostream>

VecVec FixedPointLinear(Matrix& T, Vector& c, Vector& x0, int n, bool useNewX, double tol) {
	// TODO add Excecption checks
	Vector Xold = new Vector(x0);
	Vector Xnew = new Vector(x0);
	Vector Xmid = new Vector(x0);
	double err = 1;
	std::vector<double> errvec;
	int k = 0;

	while (err > tol) {
		k++;
		for (int i = 0; i < n; i++) {
			//std::cout << "T[" << i << "][:] * X  + c[i] =  < ";
			//(T.getRow(i)).print(); std::cout << " > * < "; Xold.print();
			//std::cout << " >  + " << c[i] << "  \t= " << T.getRow(i) * Xold + c[i] << std::endl;
			if (useNewX) {
				double a = 0;
				for (int j = 0; j < n; j++) {
					a += T[i][j] * ((j >= i)*Xold[j] + (i > j)*Xnew[j]);
				}
				Xnew.set(a + c[i], i);
			} else {
				Xnew.set(T.getRow(i) * Xold + c[i], i);
			}
		}
		//Xnew.print(); std::cout << std::endl;
		err = (Xnew - Xold).norm();
		Xold = Xnew;
		errvec.emplace_back(err);
	}
	return VecVec(Xnew, errvec);
}

VecVec JacobiMethod(Matrix A, Vector b, Vector x0) {
	Matrix D = A.getDiag();
	Matrix L = -A.getUpper();
	Matrix U = -A.getLower();
	Matrix Dinv = D.invDiag();

	Matrix T = Dinv * (L + U); 
	Vector c = Dinv * b;

	return FixedPointLinear(T, c, x0, A.getn());
}

VecVec Gauss_SeidelMethod(Matrix A, Vector b, Vector x0) {
	Matrix D = A.getDiag();
	Matrix L = -A.getUpper();
	Matrix U = -A.getLower();
	Matrix DLinv = Matrix(&A);
	Matrix DL = D - L;
	for (int i = 0; i < A.getn(); i++) {
		auto ans = JacobiMethod(DL, Vector::getBasis(A.getn(), i), x0);
		Vector col = ans.ans;
		DLinv.setCol(col, i);
	}
	Matrix T = DLinv * U;
	Vector c = DLinv * b;


	return FixedPointLinear(T, c, x0, A.getn(), true);
}

VecVec SOR_Method(Matrix A, Vector b, Vector x0, double w) {
	Matrix D = A.getDiag();
	Matrix L = -A.getUpper();
	Matrix U = -A.getLower();
	Matrix DwLinv = A;
	Matrix DwL = D *(1.f/w) - L;
	for (int i = 0; i < A.getn(); i++) {
		auto ans = JacobiMethod(DwL, Vector::getBasis(A.getn(), i), x0);
		Vector col = ans.ans;
		DwLinv.setCol(col, i);
	}


	Matrix B = ((1.f / w - 1.f) * D + U);
	Matrix T = DwLinv * B;
	Vector c = DwLinv * b;

	return FixedPointLinear(T, c, x0, A.getn(), true);
}


