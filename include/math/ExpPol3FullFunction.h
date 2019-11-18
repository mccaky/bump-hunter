#include <FitFunction.h>

class ExpPol3FullFunction: public FitFunction {
	using FitFunction::FitFunction;
	
	protected:
		double calculate(double *x, double *par);
};