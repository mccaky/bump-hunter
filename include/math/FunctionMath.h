class FunctionMath {
	public:
		static double Order3BackgroundFunction(double x, double p0, double p1, double p2, double p3);
		static double Order5BackgroundFunction(double x, double p0, double p1, double p2, double p3, double p4, double p5);
		static double Gaussian(double x, double amplitude, double mean, double stddev);
	
	private:
		static double Order3BackgroundFunctionBase(double x, double p0, double p1, double p2, double p3);
		static double Order5BackgroundFunctionBase(double x, double p0, double p1, double p2, double p3, double p4, double p5);
};
