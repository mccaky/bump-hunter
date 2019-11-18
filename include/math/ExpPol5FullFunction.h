#include <FitFunction.h>

class ExpPol5FullFunction: public FitFunction {
	using FitFunction::FitFunction;
	
	protected:
		double calculate(double *x, double *par);
};