#include<TCanvas.h>
#include<TH1F.h>
#include<TRandom3.h>
#include<TF1.h>
#include<TLegend.h>

void lesson08()
{
    // 创建画布
    TCanvas *c8 = new TCanvas("c8", "Fit Result");

    // 创建一个直方图
    TH1F *h8 = new TH1F("h8", "Particle pT Spectrum; pT(Gev/c); N(pT)", 100, 0, 10);

    TRandom3 random;

    for (int i = 0; i < 100000; i++) 
    {
        double pT = random.Exp(2); // Generate a random pT from an exponential distribution
        h8->Fill(pT); // Fill the histogram with the generated pT
    }

    TF1 *fit = new TF1("fit", "[0]*exp(-x/[1])", 0, 10); // Define an exponential function
    fit->SetParameters(50000, 2); // Set initial parameters for the fit
    h8->Fit(fit, "RN"); // Fit the histogram with the function

    //set line color and width for the fit function
    fit->SetLineColor(kGreen);
    fit->SetLineWidth(2);
    h8->Draw();
    fit->Draw("SAME");


    TLegend *legend = new TLegend(0.6, 0.7, 0.9, 0.9);
    legend->AddEntry(h8, "pT spectrum", "lp");
    legend->AddEntry(fit, "Exponential Fit", "l");

    legend->Draw();

    c8->SaveAs("lesson08.pdf");
}