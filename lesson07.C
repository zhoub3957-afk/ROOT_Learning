#include<TCanvas.h>
#include<TH1F.h>
#include<TF1.h>
#include<TRandom3.h>
#include<iostream>

using namespace std;

void lesson07()
{
    // 创建画布
    TCanvas *c7 = new TCanvas("c7", "pT Fit");

    // 创建一个直方图
    TH1F *h7 = new TH1F("h7", "Particle pT Spectrum", 100, 0, 10);

    TRandom3 random;

    for (int i = 0; i < 100000; i++) 
    {
        double pT = random.Exp(2); // Generate a random pT from an exponential distribution
         h7->Fill(pT); // Fill the histogram with the generated pT
    }

    TF1 *fit = new TF1("fit", "[0]*exp(-x/[1])", 0, 10); // Define an exponential function
    fit->SetParameters(50000, 2); // Set initial parameters for the fit function
    h7->Fit(fit, "R"); // Fit the histogram with the function

    double A = fit->GetParameter(0);
    double T = fit->GetParameter(1);

    double A_error = fit->GetParError(0);
    double T_error = fit->GetParError(1);

    cout << "Fitted parameters:" << endl;
    cout << "A = " << A << " ± " << A_error << endl;
    cout << "T = " << T << " ± " << T_error << endl;

    h7->GetXaxis()->SetTitle("pT (GeV/c)");
    h7->GetYaxis()->SetTitle("N(pT)");

    h7->Draw();
}
