#include <ExpPol5BkgFunction.h>
#include <FunctionMath.h>

double ExpPol5BkgFunction::calculateBackground(double *x, double *par) {
	double xp = FitFunction::getCorrectedX(x[0]);
	return FunctionMath::Order5BackgroundFunction(xp, par[0], par[1], par[2], par[3], par[4], par[5]);
}