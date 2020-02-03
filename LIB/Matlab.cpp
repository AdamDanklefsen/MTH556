#include "Matlab.h"

using namespace matlab::engine;

std::unique_ptr<matlab::engine::MATLABEngine> getMatlabEngine() {
	return startMATLAB();
}

void MatlabPlot(std::unique_ptr<matlab::engine::MATLABEngine> eng, std::vector<double> x) {
	double* dat = new double[10];
	matlab::data::ArrayFactory factory;
	matlab::data::ArrayDimensions size; size.push_back(x.size());
	matlab::data::Array X = factory.createArray(size, &dat[0], &dat[9]);
	std::vector<matlab::data::Array> args({ X });
	eng->feval(u"plot",args);
}

void MatlabPlot(std::unique_ptr<matlab::engine::MATLABEngine> eng, std::vector<double> x, std::vector<double> y) {}
