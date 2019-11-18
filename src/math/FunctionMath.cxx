#include <FunctionMath.h>
#include <TMath.h>

double FunctionMath::Order3BackgroundFunction(double x, double p0, double p1, double p2, double p3) {
	double pol = FunctionMath::Order3BackgroundFunctionBase(x, p0, p1, p2, p3);
	return TMath::Power(10, pol);
}

double FunctionMath::Order5BackgroundFunction(double x, double p0, double p1, double p2, double p3, double p4, double p5) {
	double pol = FunctionMath::Order5BackgroundFunctionBase(x, p0, p1, p2, p3, p4, p5);
	return TMath::Power(10, pol);
}

double FunctionMath::Gaussian(double x, double amplitude, double mean, double stddev) {
	return amplitude * 1.0 / (sqrt(2.0 * TMath::Pi() * pow(stddev, 2))) * TMath::Exp(-pow((x - mean), 2) / (2.0 * pow(stddev, 2)));
}

double FunctionMath::Order3BackgroundFunctionBase(double x, double p0, double p1, double p2, double p3) {
	// Chebyshevs between given limits.
	double t0 = p0;
	double t1 = p1 * x;
	double t2 = p2 * (2 * x * x - 1);
	double t3 = p3 * (4 * x * x * x - 3 * x);
	
	return t0 + t1 + t2 + t3;
}

double FunctionMath::Order5BackgroundFunctionBase(double x, double p0, double p1, double p2, double p3, double p4, double p5) {
	// Chebyshevs between given limits. The 5th order is identical to
	// the 3rd order, but with a few additional terms.
	double o3Base = FunctionMath::Order3BackgroundFunctionBase(x, p0, p1, p2, p3);
	double t4 = p4 * (8 * x * x * x * x - 8 * x * x + 1);
	double t5 = p5 * (16 * x * x * x * x * x - 20 * x * x * x + 5 * x);
	
	return o3Base + t4 + t5;
}