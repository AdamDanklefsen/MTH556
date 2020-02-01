#include "Vector.h"
#include "Matrix.h"
#include <vector>

struct VecVec {
	VecVec(Vector a, std::vector<double> b) : ans(a), errvec(b){ }
	Vector ans;
	std::vector<double> errvec;
};

VecVec FixedPointLinear(Matrix& T, Vector& c, Vector& x0, int n, bool useNewX = false, double tol = 1e-7);

VecVec JacobiMethod(Matrix A, Vector b, Vector x0);
VecVec Gauss_SeidelMethod(Matrix A, Vector b, Vector x0);
VecVec SOR_Method(Matrix A, Vector b, Vector x0, double w);