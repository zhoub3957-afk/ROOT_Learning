#include <iostream>

#include "TH1F.h"
#include "TCanvas.h"
#include "TGraphErrors.h"

using namespace std;

void lesson18_hist_to_graph()
{
    // 1. Create histogram
    TH1F *h = new TH1F(
        "h",
        "Particle Yield;p_{T} (GeV/c);Counts",
        10,
        0,
        5
    );

    // 2. Set bin contents
    h->SetBinContent(2, 100);
    h->SetBinContent(3, 64);
    h->SetBinContent(4, 49);
    h->SetBinContent(5, 36);
    h->SetBinContent(6, 25);

    // 3. Set statistical errors
    h->SetBinError(2, 10);
    h->SetBinError(3, 8);
    h->SetBinError(4, 7);
    h->SetBinError(5, 6);
    h->SetBinError(6, 5);

    // 4. Number of data points
    const int n = 5;

    double x[n];
    double y[n];
    double ex[n];
    double ey[n];

    // 5. Read data from histogram
    for (int i = 0; i < n; i++)
    {
        int bin = i + 2;

        x[i] = h->GetBinCenter(bin);
        y[i] = h->GetBinContent(bin);

        ex[i] = h->GetBinWidth(bin) / 2.0;
        ey[i] = h->GetBinError(bin);
    }

    // 6. Print values
    for (int i = 0; i < n; i++)
    {
        cout << "Point " << i + 1
             << ": x = " << x[i]
             << ", y = " << y[i]
             << " +/- " << ey[i]
             << endl;
    }

    // 7. Create TGraphErrors
    TGraphErrors *graph =
        new TGraphErrors(n, x, y, ex, ey);

    graph->SetTitle(
        "Particle Yield;p_{T} (GeV/c);Counts"
    );

    graph->SetMarkerStyle(20);

    // 8. Draw
    TCanvas *c = new TCanvas(
        "c18",
        "Histogram to TGraphErrors",
        800,
        600
    );

    graph->Draw("AP");

    // 9. Save
    c->SaveAs(
        "plots/lesson18_hist_to_graph.png"
    );
}