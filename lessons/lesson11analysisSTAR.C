#include <TCanvas.h>
#include <TF1.h>
#include <TFile.h>
#include <TH1F.h>
#include <TLegend.h>
#include <TTree.h>
#include <cmath>
#include <iostream>

void lesson11analysisSTAR()
{
    // 打开 ROOT 文件
    TFile *file = TFile::Open("data/star.root", "READ");
    if (!file || file->IsZombie()) {
        std::cerr << "Error: cannot open data/star.root" << std::endl;
        delete file;
        return;
    }

    // 从文件中读取树
    TTree *tree = nullptr;
    file->GetObject("EventTree", tree);
    if (!tree) {
        std::cerr << "Error: EventTree not found in data/star.root" << std::endl;
        file->Close();
        delete file;
        return;
    }

    // 定义变量并绑定 TTree 分支
    double pt = 0.0;
    double eta = 0.0;
    double phi = 0.0;
    tree->SetBranchAddress("pt", &pt);
    tree->SetBranchAddress("eta", &eta);
    tree->SetBranchAddress("phi", &phi);

    TCanvas *c11 = new TCanvas("c11", "STAR pT Analysis", 800, 600);
    TH1F *hpt = new TH1F(
        "hpt",
        "p_{T} Distribution from STAR Tree; p_{T} (GeV/c); Counts",
        100, 0.2, 5.0
    );

    // 遍历 TTree，并进行基本运动学选择
    const Long64_t nEntries = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);

        if (pt < 0.2) continue;
        if (std::abs(eta) > 1.0) continue;

        hpt->Fill(pt);
    }

    // 指数函数拟合：A * exp(-pT / T)
    TF1 *fit = new TF1("fit", "[0]*exp(-x/[1])", 0.2, 5.0);
    fit->SetParameters(5000, 0.8);
    hpt->Fit(fit, "R");

    TLegend *legend = new TLegend(0.60, 0.70, 0.88, 0.88);
    legend->AddEntry(hpt, "p_{T} spectrum", "l");
    legend->AddEntry(fit, "Exponential fit", "l");

    hpt->Draw();
    fit->Draw("SAME");
    legend->Draw();
    c11->SaveAs("plots/STAR_pT_Distribution.pdf");

    file->Close();
    delete file;
}

