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
    double ey[n] = {1, 1, 1, 1, 1};

    TGraphErrors *graph = new TGraphErrors(n, x, y, ex, ey);
    graph->SetTitle("Linear Fit with Experimental Errors;" "x;" "y;");
    graph->SetMarkerStyle(20);

    TF1 *fit = new TF1("fit", "[0] * x + [1]", 0, 4);
    fit->SetParameters(0, 2);
    fit->SetParameters(1, 1);


    TCanvas *c19 = new TCanvas("c19", "TGraphErrors Linear Fit", 800, 600);
    graph->Draw("AP");
    graph->Fit(fit, "R");

    double slope = fit->GetParameter(0);
    double slope_error = fit->GetParError(0);

    double intercept = fit->GetParameter(1);
    double intercept_error = fit->GetParError(1);
    
    // Get fit quality
    double chi2 = fit->GetChisquare();
    double ndf = fit->GetNDF();

    double chi2ndf = chi2 / ndf;

    // Print results
    cout << endl;
    cout << "===== Fit Results =====" << endl;
    cout << "Slope = " << slope << " +/- " << slope_error << endl;
    cout << "Intercept = " << intercept << " +/- " << intercept_error << endl;
    cout << "Chi2 = " << chi2 << endl;
    cout << "NDF = " << ndf << endl;
    cout << "Chi2/NDF = "<< chi2ndf << endl;

    c19->SaveAs("plots/lesson19_linear_fit.png");
}
