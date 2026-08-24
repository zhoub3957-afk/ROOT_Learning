#include <TCanvas.h>
#include <TF1.h>
#include <TGraphErrors.h>
#include <iostream>

using namespace std;

void lesson20()
{
    // ==========================================
    // 1. Simulated particle pT spectrum
    // ==========================================

    const int n = 8;

    double pT[n] = {
        0.25, 0.50, 0.75, 1.00,
        1.25, 1.50, 1.75, 2.00
    };

    double yield[n] = {
        780, 590, 450, 340,
        260, 195, 150, 112
    };

    double ey[n] = {
        28, 25, 22, 19,
        16, 14, 12, 10
    };

    // ==========================================
    // 2. Create TGraphErrors
    // ==========================================

    TGraphErrors *graph =
        new TGraphErrors(n, pT, yield, nullptr, ey);

    graph->SetTitle(
        "Simulated Particle p_{T} Spectrum;"
        "p_{T} (GeV/c);"
        "dN/dp_{T}"
    );

    graph->SetMarkerStyle(20);

    // ==========================================
    // 3. Define exponential fit model
    //
    // f(pT) = A * exp(-pT / T)
    // [0] = A
    // [1] = T
    // ==========================================

    TF1 *fit =
        new TF1(
            "fit",
            "[0]*exp(-x/[1])",
            0.2,
            2.0
        );

    fit->SetParameters(1000, 0.8);

    // ==========================================
    // 4. Create canvas and draw data
    // ==========================================

    TCanvas *c20 =
        new TCanvas(
            "c20",
            "Simulated Particle pT Spectrum",
            800,
            600
        );

    graph->Draw("AP");

    // ==========================================
    // 5. Perform fit
    // ==========================================

    graph->Fit(fit, "R");

    // ==========================================
    // 6. Extract fit parameters and uncertainties
    // ==========================================

    double A = fit->GetParameter(0);
    double AError = fit->GetParError(0);

    double T = fit->GetParameter(1);
    double TError = fit->GetParError(1);

    double chi2 = fit->GetChisquare();
    double ndf = fit->GetNDF();

    // ==========================================
    // 7. Print fit results
    // ==========================================

    cout << endl;
    cout << "===== Exponential pT Fit Results =====" << endl;

    cout << "A = "
         << A << " +/- "
         << AError << endl;

    cout << "T = "
         << T << " +/- "
         << TError
         << " GeV/c" << endl;

    cout << "Chi2 = "
         << chi2 << endl;

    cout << "NDF = "
         << ndf << endl;

    cout << "Chi2/NDF = "
         << chi2 / ndf << endl;

    // ==========================================
    // 8. Save plot
    // ==========================================

    c20->SaveAs("plots/lesson20.png");
}
