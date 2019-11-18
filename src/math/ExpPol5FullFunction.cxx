#include <ExpPol5FullFunction.h>
#include <FunctionMath.h>

double ExpPol5FullFunction::calculateBackground(double *x, double *par) {
	double xp = FitFunction::getCorrectedX(x[0]);
	return FunctionMath::Order5BackgroundFunction(xp, par[0], par[1], par[2], par[3], par[4], par[5]);
}

double ExpPol5FullFunction::calculateSignal(double *x, double *par) {
	double xp = FitFunction::getCorrectedX(x[0]);
	return 0.0001 * FunctionMath::Gaussian(xp, par[6], par[7], par[8]);
}