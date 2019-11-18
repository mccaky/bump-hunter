#include <FitFunction.h>

class ExpPol5BkgFunction: public FitFunction {
	using FitFunction::FitFunction;
	
	protected:
		double calculate(double *x, double *par);
};