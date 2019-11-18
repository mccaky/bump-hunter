#include <ExpPol5BkgFunction.h>
#include <FunctionMath.h>

ExpPol5BkgFunction::ExpPol5BkgFunction(double mass_hypothesis, double window_size)
	: mass_hypothesis_(mass_hypothesis),
	  window_size_(window_size) { 
}

double ExpPol5BkgFunction::operator() (double *x, double *par) {
	double xp = (x[0] - mass_hypothesis_) / (window_size_ * 2.0);
	return FunctionMath::Order5BackgroundFunction(xp, par[0], par[1], par[2], par[3], par[4], par[5]);
}
