#include "Lib_nLinear.h"

vecVec NewtonsMethod(long double(*f)(long double), long double(*fp)(long double), long double x0, long double tol, int Nmax) {
	long double err = 1;
	long double x = x0;
	std::vector<long double> errvec;
	std::vector<long double> X; X.emplace_back(x);
	while (err > tol) {
		x -= f(x) / fp(x);
		err = f(x);
		errvec.emplace_back(err);
		X.emplace_back(x);
		//std::cout << X.size() << "\t" << x << std::endl;
	}



	return vecVec(X,errvec);
}