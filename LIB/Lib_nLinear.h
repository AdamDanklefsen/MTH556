#pragma once
#include "Common.h"

vecVec NewtonsMethod(long double (*f)(long double), long double (*fp)(long double), long double x0, long double tol, int Nmax);