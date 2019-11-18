#include <ExpPol3FullFunction.h>
#include <FunctionMath.h>

double ExpPol3FullFunction::calculateBackground(double *x, double *par) {
	double xp = FitFunction::getCorrectedX(x[0]);
	return FunctionMath::Order3BackgroundFunction(xp, par[0], par[1], par[2], par[3]);
}

double ExpPol3FullFunction::calculateSignal(double *x, double *par) {
	double xp = FitFunction::getCorrectedX(x[0]);
	if(fit_model == FitFunction::FitModel::GAUSSIAN) {
		return 0.0001 * FunctionMath::Gaussian(xp, par[4], par[5], par[6]);
	} else if(fit_model == FitFunction::FitModel::CRYSTAL_BALL) {
		return 0.0001 * FunctionMath::CrystalBall(xp, par[4], par[5], par[6], par[7], par[8]);
	}else {
		return 0.0;
	}
}