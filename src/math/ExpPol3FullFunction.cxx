#include <ExpPol3FullFunction.h>
#include <FunctionMath.h>

ExpPol3FullFunction::ExpPol3FullFunction(double mass_hypothesis, double window_size)
	: mass_hypothesis_(mass_hypothesis),
	  window_size_(window_size) {
}

double ExpPol3FullFunction::operator() (double *x, double *par) {
	double xp = (x[0] - mass_hypothesis_) / (window_size_ * 2.0);
	
	double background = FunctionMath::Order3BackgroundFunction(xp, par[0], par[1], par[2], par[3]);
	double gaussian = FunctionMath::Gaussian(xp, par[4], par[5], par[6]);
	
	return background + 0.0001 * gaussian;
}
