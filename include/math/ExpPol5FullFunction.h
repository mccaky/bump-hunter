#include <FitFunction.h>

class ExpPol5FullFunction: public FitFunction {
	using FitFunction::FitFunction;
	
	protected:
		double calculateBackground(double *x, double *par);
		double calculateSignal(double *x, double *par);
};