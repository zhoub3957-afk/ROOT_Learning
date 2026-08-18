#include<TCanvas.h>
#include<TGraphErrors.h>

void lesson17_TGraphErrors()
{

    TCanvas *c17 = new TCanvas("c17", "TGraphErrors Example");
    // 创建一个TGraphErrors对象
    const int nPoints = 5;
    double x[nPoints] =  {0.5, 1.0, 1.5, 2.0, 2.5};
    double y[nPoints] = {100, 80, 60, 45, 30};
    double ex[nPoints] = {0, 0, 0, 0, 0};
    double ey[nPoints] = {10, 9, 8, 7, 6};

    TGraphErrors *g17 = new TGraphErrors(nPoints, x, y, ex, ey);

    g17->SetTitle("Particle Yield;pT (GeV/c);Yield");

    g17->SetMarkerStyle(20);
    g17->SetMarkerSize(1.3);
    // g17->SetMarkerColor(kRed);
    g17->Draw("AP");

    c17->SaveAs("plots/lesson17_TGraphErrors.png");
}