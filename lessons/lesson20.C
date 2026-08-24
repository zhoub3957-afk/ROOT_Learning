#include <TCanvas.h>
#include <TF1.h>
#include <TGraphErrors.h>
#include <iostream>

using namespace std;

void lesson20()
{
    const int n = 8;

    double pT[n] = {0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2};
    double yield[n] = {780, 590, 450, 340, 260, 195, 150, 112};

    double ey[n] = {28, 25, 22, 19, 16, 14, 12, 10};

    TGraphErrors *graph = new TGraphErrors(n, pT, yield, nullptr, ey);
    graph->SetTitle("Simulated Particle p_{T} Spectrum;" "p_{T} (GeV/c);" "dN/dp_{T} ");
    graph->SetMarkerStyle(20);
    
    TF1 *fit = new TF1("fit", "[0]*exp(-x/[1])", 0.2, 2.5);
    fit->SetParameters(1000, 0.5);
    graph->Fit(fit, "R");

    TCanvas *c20 = new TCanvas("c20", "Simulated Particle pT Spectrum", 800, 600);
    graph->Draw("AP");

    double A = fit->GetParameter(0);
    double A_error = fit->GetParError(0);

    double T = fit->GetParameter(1);
    double T_error = fit->GetParError(1);

    double chi2 = fit->GetChisquare();
    double ndf = fit->GetNDF();

    cout << endl;

    cout << "===== Fit Results =====" << endl;

    cout << "A = " << A << " +/- " << A_error << endl;
    cout << "T = " << T << " +/- " << T_error << endl;
    cout << "Chi2 = " << chi2 << endl;
    cout << "NDF = " << ndf << endl;
    cout << "Chi2/NDF = "<< chi2/ndf << endl;

    c20->SaveAs("plots/lesson20.png");

}

