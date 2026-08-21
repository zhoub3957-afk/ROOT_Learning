#include <TCanvas.h>
#include <TF1.h>
#include <TGraphErrors.h>
#include <iostream>

using namespace std;

void lesson19()
{
    const int n = 5;

    double x[n] = {0, 1, 2, 3, 4};
    double y[n] = {1.1, 2.9, 5.2, 6.8, 9.1};
    double ex[n] = {0, 0, 0, 0, 0};
    double ey[n] = {0.1, 0.2, 0.3, 0.4, 0.5};

    TGraphErrors *graph = new TGraphErrors(n, x, y, ex, ey);
    graph->SetTitle("Linear Fit with Experimental Errors;" "x;" "y;");
    graph->SetMarkerStyle(20);

    TF1 *fit = new TF1("fit", "[0] * x + [1]", 0, 4);
    fit->SetParameters(0, 2);
    fit->SetParameters(1, 1);

    TCanvas *c19 = new TCanvas("c19", "TGraphErrors Linear Fit", 800, 600);
    graph->Draw("AP");
    graph->Fit(fit, "R");
    c19->SaveAs("plots/lesson19_linear_fit.png");
}
