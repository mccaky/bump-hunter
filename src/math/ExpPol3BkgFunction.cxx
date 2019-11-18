#include <ExpPol3BkgFunction.h>
#include <FunctionMath.h>

double ExpPol3BkgFunction::calculateBackground(double *x, double *par) {
	double xp = FitFunction::getCorrectedX(x[0]);
	return FunctionMath::Order3BackgroundFunction(xp, par[0], par[1], par[2], par[3]);
}