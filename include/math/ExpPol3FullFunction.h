#include <FitFunction.h>

class ExpPol3FullFunction: public FitFunction {
	using FitFunction::FitFunction;
	
	protected:
		double calculateBackground(double *x, double *par);
		double calculateSignal(double *x, double *par);
};