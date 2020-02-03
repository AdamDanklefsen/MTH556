#pragma once
#include "Vector.h"
#include "Matrix.h"
#include <vector>
#include "Common.h"




VecVec FixedPointLinear(Matrix& T, Vector& c, Vector& x0, int n, bool useNewX = false, double tol = 1e-7);

VecVec JacobiMethod(Matrix A, Vector b, Vector x0);
VecVec Gauss_SeidelMethod(Matrix A, Vector b, Vector x0);
VecVec SOR_Method(Matrix A, Vector b, Vector x0, double w);


VecVec ConjGradMethod(Matrix A, Vector b, Vector x0, int n, double tol = 1e-7);
double getLambda(Matrix A, Vector b, Vector d, Vector x);
double getAlpha(Matrix A, Vector b, Vector d, Vector x);