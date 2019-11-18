#include <ExpPol5FullFunction.h>
#include <FunctionMath.h>

ExpPol5FullFunction::ExpPol5FullFunction(double mass_hypothesis, double window_size)
	: mass_hypothesis_(mass_hypothesis),
	  window_size_(window_size) {
}

double ExpPol5FullFunction::operator() (double *x, double *par) {
	double xp = (x[0] - mass_hypothesis_) / (window_size_ * 2.0);
	
	double background = FunctionMath::Order5BackgroundFunction(xp, par[0], par[1], par[2], par[3], par[4], par[5]);
	double gaussian = FunctionMath::Gaussian(xp, par[6], par[7], par[8]);
	
	return background + 0.0001 * gaussian;
}
