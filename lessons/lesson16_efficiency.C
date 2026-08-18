#include <TCanvas.h>
#include <TH1F.h>

#include <cstdlib>
#include <iostream>

void lesson16_efficiency()
{
    // 未修正的 pT 谱
    TH1F *hMeasured = new TH1F(
        "hMeasured",
        "Measured and Efficiency-Corrected p_{T} Spectrum; p_{T} (GeV/c); Counts",
        50, 0, 5
    );
    hMeasured->Sumw2();

    // 效率修正后的 pT 谱
    TH1F *hCorrected = new TH1F(
        "hCorrected",
        "Measured and Efficiency-Corrected p_{T} Spectrum; p_{T} (GeV/c); Counts",
        50, 0, 5
    );
    hCorrected->Sumw2();

    for (int i = 0; i < 10000; ++i) {
        const double pt = 0.2 + 4.8 * static_cast<double>(std::rand()) / RAND_MAX;

        // 教学示例：假设探测效率随 pT 线性增加
        double efficiency = 0.4 + 0.1 * pt;
        if (efficiency > 1.0)
            efficiency = 1.0;

        // 未修正谱
        hMeasured->Fill(pt);

        // 效率修正：每个观测事件按 1/efficiency 加权
        const double weight = 1.0 / efficiency;
        hCorrected->Fill(pt, weight);
    }

    TCanvas *c16 = new TCanvas("c16", "Efficiency Correction", 800, 600);
    hMeasured->SetLineColor(kBlue);
    hCorrected->SetLineColor(kRed);

    hMeasured->Draw();
    hCorrected->Draw("SAME");

    c16->SaveAs("lesson16_efficiency.png");
}
