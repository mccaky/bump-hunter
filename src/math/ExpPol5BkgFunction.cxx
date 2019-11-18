#include <ExpPol5BkgFunction.h>
#include <TMath.h>

ExpPol5BkgFunction::ExpPol5BkgFunction(double mass_hypothesis, double window_size)
	: mass_hypothesis_(mass_hypothesis),
	  window_size_(window_size) { 
}

double ExpPol5BkgFunction::operator() (double *x, double *par) {
	double xp = (x[0] - mass_hypothesis_) / (window_size_ * 2.0);
	
	// Chebyshevs between given limits
	double t0 = par[0];
	double t1 = par[1] * xp;
	double t2 = par[2] * (2 * xp * xp - 1);
	double t3 = par[3] * (4 * xp * xp * xp - 3 * xp);
	double t4 = par[4] * (8 * xp * xp * xp * xp - 8 * xp * xp + 1);
	double t5 = par[5] * (16 * xp * xp * xp * xp * xp - 20 * xp * xp * xp + 5 * xp);
	
	double pol = t0 + t1 + t2 + t3 + t4 + t5;
	
	return TMath::Power(10, pol);
}