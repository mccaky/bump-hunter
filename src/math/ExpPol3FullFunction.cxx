#include <ExpPol3FullFunction.h>
#include <TMath.h>

ExpPol3FullFunction::ExpPol3FullFunction(double mass_hypothesis, double window_size)
	: mass_hypothesis_(mass_hypothesis),
	  window_size_(window_size) {
}

double ExpPol3FullFunction::operator() (double *x, double *par) {
	double xp = (x[0] - mass_hypothesis_) / (window_size_ * 2.0);
	
	// Chebyshevs between given limits
	double t0 = par[0];
	double t1 = par[1] * xp;
	double t2 = par[2] * (2 * xp * xp - 1);
	double t3 = par[3] * (4 * xp * xp * xp - 3 * xp);
	
	double pol = t0 + t1 + t2 + t3;
	
	double gauss = (1.0) / (sqrt(2.0 * TMath::Pi() * pow(par[6],2))) * TMath::Exp(-pow((xp - par[5]), 2) / (2.0 * pow(par[6], 2)));
	
	return TMath::Power(10, pol) + 0.0001 * par[4] * gauss;
}