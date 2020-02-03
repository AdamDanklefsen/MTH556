#pragma once
#include <vector>
#include "MatlabEngine.hpp"
#include "MatlabDataArray.hpp"

std::unique_ptr<matlab::engine::MATLABEngine> getMatlabEngine();

void MatlabPlot(std::unique_ptr<matlab::engine::MATLABEngine> eng, std::vector<double> x);
void MatlabPlot(std::unique_ptr<matlab::engine::MATLABEngine> eng, std::vector<double> x, std::vector<double> y);
