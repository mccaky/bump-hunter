#include <ExpPol5FullFunction.h>
#include <TMath.h>

ExpPol5FullFunction::ExpPol5FullFunction(double mass_hypothesis, double window_size)
	: mass_hypothesis_(mass_hypothesis),
	  window_size_(window_size) {
}

double ExpPol5FullFunction::operator() (double *x, double *par) {
	double xp = (x[0] - mass_hypothesis_) / (window_size_ * 2.0);
	
	// Chebyshevs between given limits
	double t0 = par[0];
	double t1 = par[1] * xp;
	double t2 = par[2] * (2 * xp * xp - 1);
	double t3 = par[3] * (4 * xp * xp * xp - 3 * xp);
	double t4 = par[4] * (8 * xp * xp * xp * xp - 8 * xp * xp + 1);
	double t5 = par[5] * (16 * xp * xp * xp *xp * xp - 20 * xp * xp * xp + 5 * xp);
	
	double pol = t0 + t1 + t2 + t3 + t4 + t5;
	
	double gauss = (1.0) / (sqrt(2.0 * TMath::Pi() * pow(par[8], 2))) * TMath::Exp(-pow((xp - par[7]), 2) / (2.0 * pow(par[8], 2)));
	
	return TMath::Power(10, pol) + 0.0001 * par[6] * gauss;
}