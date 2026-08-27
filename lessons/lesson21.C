#include <TCanvas.h>
#include <TH1F.h>
#include <TF1.h>
#include <iostream>

using namespace std;

void lesson21()
{
    const int nBins = 10;
    TH1F *h = new TH1F("h", "Particle p_{T} Spectrum; p_{T} (GeV/c); Counts", nBins, 0, 2);

    // Fill the histogram with random numbers from an exponential distribution
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

    // Draw the histogram
    TCanvas *c21 = new TCanvas("c21", "Lesson 21", 800, 600);
    h->Draw("E"); // Draw with error bars
    c21->SaveAs("plots/lesson21.png");
}
    