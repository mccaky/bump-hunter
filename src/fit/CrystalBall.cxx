#include <cmath>
#include "CrystalBall.h"

Double_t calcA(Double_t n, Double_t absAlpha) {
	return pow(n / absAlpha, n) * exp(-pow(absAlpha, 2) / 2);
}

Double_t calcB(Double_t n, Double_t absAlpha) {
	return (n / absAlpha) - absAlpha;
}

Double_t crystalBall(Double_t *x, Double_t *par) {
	// Parameters correspond to alpha, n, mean, stddev, N
	Double_t alpha = par[0];
	Double_t n = par[1];
	Double_t mean = par[2];
	Double_t stddev = par[3];
	Double_t N = par[4];
	
	// The crystal ball function differs based on the value of x.
	Double_t differentiator = (x[0] - mean) / stddev;
	if(differentiator > -alpha) {
		// Return the functional value.
		return N * exp(-pow(x[0] - mean, 2) / (2 * pow(stddev, 2)));
	} else {
		// Calculate the derived parameters A and B.
		Double_t absAlpha = fabs(alpha);
		Double_t A = calcA(n, absAlpha);
		Double_t B = calcB(n, absAlpha);
		
		// Return the functional value.
		return N * A * pow(B - ((x[0] - mean) / stddev), -n);
	}
}

TF1* getCrystalBallFunction(Double_t xMin, Double_t xMax) {
	TF1 *cbf = new TF1("cbf", crystalBall, xMin, xMax, 5);
	cbf->SetParNames("alpha", "n", "mean", "stddev", "N");
	return cbf;
}

void displayFunction(Double_t alpha, Double_t n, Double_t mean, Double_t stddev, Double_t N) {
	// Create a test crystal ball distribution histogram. This is
	// generated as a perfect function using the parameters below:
	// 		α =  1.365340
	//		n =  4.570740
	//		μ = -1.383158
	// 		σ =  1.056960
	// 		N =  1.546010
	// Then, the function is sampled 52 times to create a histogram
	// which can be used to test the function's fitting capabilities.
	TH1D* testHist = new TH1D("testHist", "Crystal Ball Distribution", 50, -10, 10);
	testHist->SetBinContent(0, 0.00353863);
	testHist->SetBinContent(1, 0.00419728);
	testHist->SetBinContent(2, 0.0050116);
	testHist->SetBinContent(3, 0.00602689);
	testHist->SetBinContent(4, 0.00730432);
	testHist->SetBinContent(5, 0.00892757);
	testHist->SetBinContent(6, 0.0110126);
	testHist->SetBinContent(7, 0.0137225);
	testHist->SetBinContent(8, 0.0172906);
	testHist->SetBinContent(9, 0.0220563);
	testHist->SetBinContent(10, 0.0285237);
	testHist->SetBinContent(11, 0.0374574);
	testHist->SetBinContent(12, 0.0500464);
	testHist->SetBinContent(13, 0.0681913);
	testHist->SetBinContent(14, 0.095026);
	testHist->SetBinContent(15, 0.135907);
	testHist->SetBinContent(16, 0.200379);
	testHist->SetBinContent(17, 0.306282);
	testHist->SetBinContent(18, 0.488949);
	testHist->SetBinContent(19, 0.79689);
	testHist->SetBinContent(20, 1.14688);
	testHist->SetBinContent(21, 1.43033);
	testHist->SetBinContent(22, 1.54581);
	testHist->SetBinContent(23, 1.44769);
	testHist->SetBinContent(24, 1.17488);
	testHist->SetBinContent(25, 0.826256);
	testHist->SetBinContent(26, 0.50354);
	testHist->SetBinContent(27, 0.265922);
	testHist->SetBinContent(28, 0.121695);
	testHist->SetBinContent(29, 0.0482607);
	testHist->SetBinContent(30, 0.0165849);
	testHist->SetBinContent(31, 0.00493893);
	testHist->SetBinContent(32, 0.00127454);
	testHist->SetBinContent(33, 0.000285018);
	testHist->SetBinContent(34, 0.0000552323);
	testHist->SetBinContent(35, 0.00000927498);
	testHist->SetBinContent(36, 0.00000134969);
	testHist->SetBinContent(37, 0.000000170198);
	testHist->SetBinContent(38, 0.0000000185983);
	testHist->SetBinContent(39, 0.00000000176114);
	testHist->SetBinContent(40, 0.000000000144515);
	testHist->SetBinContent(41, 0.0000000000102762);
	testHist->SetBinContent(42, 0.00000000000063322);
	testHist->SetBinContent(43, 0.0000000000000338123);
	testHist->SetBinContent(44, 0.00000000000000156457);
	testHist->SetBinContent(45, 0.000000000000000062736);
	testHist->SetBinContent(46, 0.0000000000000000021799);
	testHist->SetBinContent(47, 0.0000000000000000000656384);
	testHist->SetBinContent(48, 0.00000000000000000000171269);
	testHist->SetBinContent(49, 0.0000000000000000000000387257);
	testHist->SetBinContent(50, 0.000000000000000000000000758788);
	testHist->SetBinContent(51, 0.0000000000000000000000000128837);
	
	// Draw the simulated crystal ball function.
	testHist->Draw();
	
	// Define the crystal ball function.
	TF1* cbf = getCrystalBallFunction(-10, 10);
	
	// Set the allowed parameter ranges and set the start values to
	// the parameter range minimums.
	cbf->SetParLimits(0,   1.0, 100); // α - Must be at least 1, no upper limit.
	cbf->SetParLimits(1,   1.0, 100); // n - Must be at least 1, no upper limit.
	cbf->SetParLimits(2,  -5.0,   5); // μ - May be any value. In this case, it is limited by the histogram size.
	cbf->SetParLimits(3,   0.1, 100); // σ - Must be greater than zero.
	cbf->SetParLimits(4,   0.1, 100); // N - Must be greater than zero.
	cbf->SetParameters(1.0, 1.0, -10.0, 0.1, 0.1);
	
	// Perform the fit.
	testHist->Fit(cbf);
	
	// Output the actual values.
	std::cout << std::endl << std::endl << "Actual Values:" << std::endl;
	std::cout << "\talpha  ::  1.365340" << std::endl;
	std::cout << "\tn      ::  4.570740" << std::endl;
	std::cout << "\tmean   :: -1.383158" << std::endl;
	std::cout << "\tstddev ::  1.056960" << std::endl;
	std::cout << "\tN      ::  1.546010" << std::endl;
}

void displayFunction() {
	displayFunction(10, 3, 0, 1, 1);
}