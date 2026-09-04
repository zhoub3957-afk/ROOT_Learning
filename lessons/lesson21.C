#include <TCanvas.h>
#include <TH1F.h>
#include <TF1.h>
#include <iostream>
#include <cmath>

using namespace std;

void lesson21()
{
    const int nBins = 10;
    TH1F *h = new TH1F("h", "Particle p_{T} Spectrum; p_{T} (GeV/c); Counts", nBins, 0, 2);

    // Fill the histogram with particle counts
    double counts[nBins] = {800, 600, 450, 340, 260, 195, 150, 115, 90, 70};
    for(int i = 0; i < nBins; i++)
    {
        h->SetBinContent(i + 1, counts[i]);
        h->SetBinError(i + 1, sqrt(counts[i])); // Set the error as the square root of counts
    }

    // calculate bin width
    double binWidth = h->GetXaxis()->GetBinWidth(1);
    cout << "Bin width = " << binWidth << "GeV/c" << endl;

    // calculate total counts
    double totalCounts = h->Integral();
    cout << "Total counts = " << totalCounts << endl;

    // convert counts to dN/dpT
    TH1F *hSpectrum = (TH1F*)h->Clone("hSpectrum");
    hSpectrum->SetTitle("Particle p_{T} Spectrum; p_{T} (GeV/c); dN/dp_{T}");
    hSpectrum->Scale(1.0 / binWidth); // Scale by 1/binWidth to get dN/dpT

    // Draw the histogram
    TCanvas *c21 = new TCanvas("c21", "Lesson 21", 800, 600);
    h->Draw("E"); // Draw with error bars
    c21->SaveAs("plots/lesson21.png");

    // Draw the dN/dpT spectrum
    TCanvas *cSpectrum = new TCanvas("c21_Spectrum", "pT Spectrum", 800, 600);
    hSpectrum->Draw("E");
    cSpectrum->SaveAs("plots/lesson21_spectrum.png");

    // Experiment B: Fine binning
    TH1F *hFine = new TH1F("hFine", "Fine Binning; p_{T} (GeV/c); Counts", 20, 0, 2);

    // Fill fine bins: each original bin is divided into two equal bins
    for (int i = 0; i < 20; i++)
    {
        double value = 0.0;

        if (i == 0 || i == 1)
            value = 400;
        else if (i == 2 || i == 3)
            value = 300;
        else if (i == 4 || i == 5)
            value = 225;
        else if (i == 6 || i == 7)
            value = 170;
        else if (i == 8 || i == 9)
            value = 130;
        else if (i == 10 || i == 11)
            value = 97.5;
        else if (i == 12 || i == 13)
            value = 75;
        else if (i == 14 || i == 15)
            value = 57.5;
        else if (i == 16 || i == 17)
            value = 45;
        else
            value = 35;

        hFine->SetBinContent(i + 1, value);
        hFine->SetBinError(i + 1, sqrt(value));
    }

    double fineWidth = hFine->GetBinWidth(1);

    cout << "Fine bin width = " << fineWidth << " GeV/c" << endl;
    cout << "Fine histogram total counts = " << hFine->Integral() << endl;

    TCanvas *cFine = new TCanvas("cFine", "Fine Binning", 800, 600);
    hFine->Draw("E");

    cFine->SaveAs("plots/lesson21_fine.png");
}
