class ExpPol3BkgFunction {
	public:
		/** Constructor */
		ExpPol3BkgFunction(double mass_hypothesis, double window_size);
		
		double operator() (double *x, double *par);
		
	private:
		/** Mass hypothesis */
		double mass_hypothesis_{0};
		
		/** Size of the search window. */
		double window_size_{0};
};