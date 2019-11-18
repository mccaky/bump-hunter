#ifndef FUNCTIONMATH_H
#define FUNCTIONMATH_H

class FunctionMath {
	public:
		/** Defines the third-order background function. */
		static double Order3BackgroundFunction(double x, double p0, double p1, double p2, double p3);
		
		/** Defines the fifth-order background function. */
		static double Order5BackgroundFunction(double x, double p0, double p1, double p2, double p3, double p4, double p5);
		
		/** Defines a Gaussian function for signal-fitting. */
		static double Gaussian(double x, double amplitude, double mean, double stddev);
	
	private:
		/**
		 * Calculates the third-order background function prior to
		 * the final exponentiation.
		 */
		static double Order3BackgroundFunctionBase(double x, double p0, double p1, double p2, double p3);
		
		/**
		 * Calculates the fifth-order background function prior to
		 * the final exponentiation.
		 */
		static double Order5BackgroundFunctionBase(double x, double p0, double p1, double p2, double p3, double p4, double p5);
};

#endif