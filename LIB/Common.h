#pragma once
#include <vector>
#include <string>
#include "Vector.h"
#include <iostream>
#include <fstream>

struct VecVec {
	VecVec(Vector a, std::vector<double> b) : ans(a), errvec(b) {}
	Vector ans;
	std::vector<double> errvec;
};
struct vecVec {
	vecVec(std::vector<long double> a, std::vector<long double> b) : ans(a), errvec(b) {}
	std::vector<long double> ans;
	std::vector<long double> errvec;
};

bool Kdelta(int i, int j);
template <typename T> void stdVectoCSV1D(std::vector<T> dat, const char* fname);

template<typename T>
inline void stdVectoCSV1D(std::vector<T> dat, const char* fname) {
	std::ofstream f;
	f.open(fname);
	for (int i = 0; i < dat.size(); i++) {
		f << dat.at(i) << std::endl;
	}
	f.close();
	return;
}
