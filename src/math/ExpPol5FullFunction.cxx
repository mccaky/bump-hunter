#include <ExpPol5FullFunction.h>
#include <FunctionMath.h>

double ExpPol5FullFunction::calculate(double *x, double *par) {
	double xp = (x[0] - mass_hypothesis) / (window_size * 2.0);
	
	double background = FunctionMath::Order5BackgroundFunction(xp, par[0], par[1], par[2], par[3], par[4], par[5]);
	double gaussian = FunctionMath::Gaussian(xp, par[6], par[7], par[8]);
	
	return background + 0.0001 * gaussian;
}