/**
 * @file FitPrinter.cxx
 * @brief Class used to print a RooFit result to a file.
 * @author Omar Moreno
 *         SLAC National Accelerator Laboratory 
 */

#include "FitPrinter.h"

FitPrinter::FitPrinter() {
}

FitPrinter::~FitPrinter() {
    delete _canvas;
}

void FitPrinter::print(TH1* histogram, double window_start, double window_end, std::string output_path) {

    TColor* fte_blue   = new TColor(5001, 0, 143, 213);
    TColor* fte_orange = new TColor(5002, 252, 79, 48);
    TColor* fte_green  = new TColor(5003, 109, 144, 79); 

    histogram->SetLineColor(kAzure+2); 
    histogram->SetMarkerColor(kAzure+2); 
    histogram->SetTitle(""); 
    histogram->GetXaxis()->CenterTitle(); 
    histogram->Draw("hist e0");

    TF1* bkg = histogram->GetFunction("bkg"); 
    bkg->SetLineColor(kGreen-1);
    bkg->Draw("same");

    TF1* comp = histogram->GetFunction("full"); 
    comp->SetLineColor(kRed+3);  
    comp->Draw("same"); 

    histogram->GetXaxis()->SetRangeUser(window_start, window_end);  

    std::cout << "[ FitPrinter ]: Saving file to: " << output_path << std::endl;
    _canvas->SetLogy(); 
    _canvas->SaveAs(output_path.c_str());
}
