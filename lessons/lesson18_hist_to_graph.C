#include<TH1F.h>
#include<TCanvas.h>
#include<TGraphErrors.h>
#include<iostream>
#include<cmath>

using namespace std;

void lesson18_hist_to_graph()
{
    // 创建一个直方图
    TH1F *h = new TH1F("h", "Particle Yield;p_{T} (GeV/c);Counts", 10, 0, 5);

    // 填充直方图数据
    h->Fill(0.5, 100);
    h->Fill(1.0, 64);
    h->Fill(1.5, 49);
    h->Fill(2.0, 36);
    h->Fill(2.5, 25);

    // 3. Create arrays for TGraphErrors
    const int n = 5;

    double x[n];
    double y[n];
    double ex[n];
    double ey[n];

    // 4. Read data from histogram
    for (int i = 0; i < n; i++)
    {
        int bin = h->FindBin(0.5 + i * 0.5);

        x[i] = h->GetBinCenter(bin);
        y[i] = h->GetBinContent(bin);

        ex[i] = h->GetBinWidth(bin) / 2.0;
        ey[i] = h->GetBinError(bin);
    }

    // 5. Print values
    for (int i = 0; i < n; i++)
    {
        
        cout << "Point " << i + 1 << ": x = " << x[i] << ", y = " << y[i] << " +/- " << ey[i] << endl;
    }

    // 6. Create TGraphErrors
    TGraphErrors *graph = new TGraphErrors(n, x, y, ex, ey);

    graph->SetTitle("Particle Yield;p_{T} (GeV/c);Counts");
    graph->SetMarkerStyle(20);

    // 7. Draw
    TCanvas *c18 = new TCanvas("c18", "Histogram to TGraphErrors", 800, 600);
    graph->Draw("AP");

    // 8. Save
    c18->SaveAs("plots/lesson18_hist_to_graph.png");
}