#include<TH1F.h>
#include<TCanvas.h>
#include<iostream>

using namespace std;

void lesson16_efficiency()
{
    // 未修正的pT谱
    TH1F *hMeasured = new TH1F("hMeasured", "Measured Efficiency; x; Counts", 50, 0, 5);
    hMeasured->Sumw2();

    // 修正后的pT谱
    TH1F *hCorrected = new TH1F("hCorrected", "Corrected Efficiency; x; Counts", 50, 0, 5);
    hCorrected->Sumw2();


    for(int i = 0; i < 10000; i++)
    {
        double pt = 0.2 + 4.8 * (double)rand() / (double)RAND_MAX;

        // 假设效率假设效率随pT增加
        double efficiency = 0.4 + 0.1 * pt; // 简单的线性效率模型

        // 防止效率超过1
        if(efficiency > 1.0) 
            efficiency = 1.0;

        // 未修正
        hMeasured->Fill(pt);

        // 效率修正
        double weight = 1.0 / efficiency;
        hCorrected->Fill(pt, weight);
    }

       // 绘图
    TCanvas *c16 = new TCanvas("c16", "Efficiency Correction"); 
    hMeasured->SetLineColor(kBlue);
    hCorrected->SetLineColor(kRed);

    hMeasured->Draw();
    hCorrected->Draw("SAME");

    c16->SaveAs("lesson16_efficiency.png");
}
