#include <TCanvas.h>
#include <TH1F.h>
#include <iostream>
#include <cmath>

using namespace std;

void lesson21_efficiency()
{
    const int nBins = 10;
    TH1F *h = new TH1F("h", "Measured p_{T} Spectrum; p_{T} (GeV/c); Counts", nBins, 0, 2);
    TH1F *hCorrected = new TH1F("hCorrected", "Efficiency Corrected p_{T} Spectrum; p_{T} (GeV/c); Counts", nBins, 0, 2);

    double counts[nBins] = {800, 600, 450, 340, 260, 195, 150, 115, 90, 70};
    double efficiency[nBins] = {0.80, 0.82, 0.85, 0.87, 0.90, 0.91, 0.92, 0.93, 0.94, 0.95};

    // Fill histograms
    for(int i = 0; i < nBins; i++)
    {
        // Measured data
        h->SetBinContent(i + 1, counts[i]);
        h->SetBinError(i + 1, sqrt(counts[i]));

        // Efficiency correction
        double corrected = counts[i] / efficiency[i];
        double error = sqrt(counts[i]) / efficiency[i];

        hCorrected->SetBinContent(i + 1, corrected);
        hCorrected->SetBinError(i + 1, error);
    }

    double binWidth = h->GetBinWidth(1);
    cout << "Bin width = " << binWidth << " GeV/c" << endl;

    // Print corrected results
    cout << "\nEfficiency corrected results:" << endl;

    for(int i = 0; i < nBins; i++)
    {
        cout << "Bin " << i + 1 << ": " << hCorrected->GetBinContent(i + 1) << " +/- " << hCorrected->GetBinError(i + 1) << endl;
    }

    // Draw measured spectrum
    TCanvas *cMeasured = new TCanvas("cMeasured", "Measured Spectrum", 800, 600);
    h->Draw("E");
    cMeasured->SaveAs( "plots/lesson21_measured.png");

    // Draw corrected spectrum
    TCanvas *cCorrected = new TCanvas("cCorrected", "Corrected Spectrum", 800, 600);
    hCorrected->Draw("E");
    cCorrected->SaveAs("plots/lesson21_corrected.png");
}