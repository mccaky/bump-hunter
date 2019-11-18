#include <FitFunction.h>

class ExpPol3BkgFunction: public FitFunction {
	using FitFunction::FitFunction;
	
	protected:
		double calculate(double *x, double *par);
};