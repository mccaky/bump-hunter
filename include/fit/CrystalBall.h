#include "TF1.h"
#include "TH1D.h"
#include "TMath.h"

Double_t calcA(Double_t n, Double_t absAlpha);
Double_t calcB(Double_t n, Double_t absAlpha);
Double_t crystalBall(Double_t *x, Double_t *par);
TF1* getCrystalBallFunction(Double_t xMin, Double_t xMax);
void displayFunction();
void displayFunction(Double_t alpha, Double_t n, Double_t mean, Double_t stddev, Double_t N);
