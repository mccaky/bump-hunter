#include <ExpPol3FullFunction.h>
#include <FunctionMath.h>

double ExpPol3FullFunction::calculate(double *x, double *par) {
	double xp = (x[0] - mass_hypothesis) / (window_size * 2.0);
	
	double background = FunctionMath::Order3BackgroundFunction(xp, par[0], par[1], par[2], par[3]);
	double gaussian = FunctionMath::Gaussian(xp, par[4], par[5], par[6]);
	
	return background + 0.0001 * gaussian;
}