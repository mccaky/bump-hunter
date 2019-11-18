#include <FitFunction.h>

class ExpPol3BkgFunction: public FitFunction {
	using FitFunction::FitFunction;
	
	protected:
		double calculateBackground(double *x, double *par);
		
		// Background-only functions do not use a signal fit.
		double calculateSignal(double *x, double *par) { return 0; }
};