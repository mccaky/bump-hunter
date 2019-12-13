/**
 * @file FitPrinter.h
 * @brief Class used to print a RooFit result to a file.
 * @author Omar Moreno
 *         SLAC National Accelerator Laboratory 
 */

#ifndef __FIT_PRINTER_H__
#define __FIT_PRINTER_H__

//----------//
//   ROOT   //
//----------//
#include <TCanvas.h>
#include <TH1.h>
#include <TF1.h>
#include <TAxis.h>
#include <TColor.h>

class FitPrinter { 
    
    public: 

        /** Default constructor */
        FitPrinter();

        /** Destructor */
        ~FitPrinter();

        /** Print the resulting fit and save it to the specified output path. */
        void print(TH1* histogram, double window_start, double window_end, std::string output_path); 

    private:
        
        /** ROOT canvas */   
        TCanvas* _canvas{new TCanvas{"canvas", "canvas", 900, 800}};
        

};  // FitPrinter

#endif // __FIT_PRINTER_H__
