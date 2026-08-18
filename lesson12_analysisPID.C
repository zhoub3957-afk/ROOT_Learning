#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TLegend.h>
#include <TStyle.h>
#include <iostream>

using namespace std;

void lesson12_analysisPID()
{
    TFile *file = new TFile("PID_simulation.root");

    TTree *tree = (TTree*)file->Get("ParticleTree");

    double pt, eta, phi;
    int pid;

    tree->SetBranchAddress("pt", &pt);
    tree->SetBranchAddress("eta", &eta);
    tree->SetBranchAddress("phi", &phi);
    tree->SetBranchAddress("pid", &pid);

    TCanvas *c12 = new TCanvas("c12", "Particle Identification Analysis");
    TH1F *hpt_pi = new TH1F("hpt_pi", "pT Distribution for Different Particles; pT (GeV/c); N(pT)", 100, 0, 5);
    TH1F *hpt_K = new TH1F("hpt_K", "pT Distribution for K+", 100, 0, 5);
    TH1F *hpt_p = new TH1F("hpt_p", "pT Distribution for proton", 100, 0, 5);

    for (int i = 0; i < tree->GetEntries(); i++)
    {
        tree->GetEntry(i);

        if (pt < 0.2) continue;
        if (abs(eta) > 1.0) continue;

        if (pid == 211)
            hpt_pi->Fill(pt);

        else if (pid == 321)
            hpt_K->Fill(pt);

        else if (pid == 2212)
            hpt_p->Fill(pt);
    }

    // 关闭统计信息框
    gStyle->SetOptStat(0);

    // 设置颜色
    hpt_pi->SetLineColor(kRed);
    hpt_K->SetLineColor(kBlue);
    hpt_p->SetLineColor(kGreen);

    // 绘制
    hpt_pi->Draw();
    hpt_K->Draw("SAME");
    hpt_p->Draw("SAME");

    // 创建Legend
    TLegend *legend = new TLegend(0.65, 0.65, 0.88, 0.88);

    legend->AddEntry(hpt_pi, "#pi^{+}", "l");
    legend->AddEntry(hpt_K, "K^{+}", "l");
    legend->AddEntry(hpt_p, "p", "l");

    legend->Draw();

    c12->SaveAs("lesson12_PID.png");

    // 创建归一化谱
    TH1F *hpt_pi_norm = (TH1F*)hpt_pi->Clone("hpt_pi_norm");
    TH1F *hpt_K_norm = (TH1F*)hpt_K->Clone("hpt_K_norm");
    TH1F *hpt_p_norm = (TH1F*)hpt_p->Clone("hpt_p_norm");

    // 归一化
    hpt_pi_norm->Scale(1.0 / hpt_pi_norm->Integral());
    hpt_K_norm->Scale(1.0 / hpt_K_norm->Integral());
    hpt_p_norm->Scale(1.0 / hpt_p_norm->Integral());

    // 绘制归一化谱
    TCanvas *c12_norm = new TCanvas("c12_norm", "Normalized pT Distribution for Different Particles");
    hpt_pi_norm->SetLineColor(kRed);
    hpt_K_norm->SetLineColor(kBlue);
    hpt_p_norm->SetLineColor(kGreen);
    hpt_pi_norm->SetTitle("Normalized pT Distribution for Different Particles; pT (GeV/c); Normalized N(pT)");

    hpt_pi_norm->Draw();
    hpt_K_norm->Draw("SAME");
    hpt_p_norm->Draw("SAME");

    // 创建Legend
    TLegend *legend_norm = new TLegend(0.65, 0.65, 0.88, 0.88);
    legend_norm->AddEntry(hpt_pi_norm, "#pi^{+}", "l");
    legend_norm->AddEntry(hpt_K_norm, "K^{+}", "l");
    legend_norm->AddEntry(hpt_p_norm, "p", "l");
    legend_norm->Draw();

    c12_norm->SaveAs("lesson12_PID_normalized.png");

    // 创建 pi/K ratio
    TH1F *hpt_piK_ratio = (TH1F*)hpt_pi->Clone("hpt_piK_ratio");
    hpt_piK_ratio->Divide(hpt_K);

    // 绘制 pi/K ratio
    TCanvas *c12_piK_ratio = new TCanvas("c12_piK_ratio", "pT Distribution Ratio #pi^{+}/K^{+}");
    hpt_piK_ratio->SetLineColor(kBlack);
    hpt_piK_ratio->SetTitle("pT Distribution Ratio #pi^{+}/K^{+}; pT (GeV/c); Ratio");

    hpt_piK_ratio->Draw();

    c12_piK_ratio->SaveAs("lesson12_PID_piK_ratio.png");

    // 创建 pi/K ratio_normalized
    TH1F *hpt_piK_ratio_norm = (TH1F*)hpt_pi_norm->Clone("hpt_piK_ratio_norm");
    hpt_piK_ratio_norm->Divide(hpt_K_norm);

    // 绘制 pi/K ratio_normalized
    TCanvas *c12_piK_ratio_norm = new TCanvas("c12_piK_ratio_norm", "pT Distribution Ratio_norm #pi^{+}/K^{+}");
    hpt_piK_ratio_norm->SetLineColor(kBlack);
    hpt_piK_ratio_norm->SetTitle("pT Distribution Ratio_norm #pi^{+}/K^{+}; pT (GeV/c); Ratio");

    hpt_piK_ratio_norm->Draw();

    c12_piK_ratio_norm->SaveAs("lesson12_PID_piK_ratio_normalized.png");

    cout << "Pion Entries = " << hpt_pi->GetEntries() << endl;
    cout << "Kaon Entries = " << hpt_K->GetEntries() << endl;
    cout << "Proton Entries = " << hpt_p->GetEntries() << endl;

    cout << "Pi bin 10 content = " << hpt_pi->GetBinContent(10) << endl;
    cout << "Pi bin 10 error = " << hpt_pi->GetBinError(10) << endl;

    cout << "K bin 10 content = " << hpt_K->GetBinContent(10) << endl;
    cout << "K bin 10 error = " << hpt_K->GetBinError(10) << endl;

    cout << "p bin 10 content = " << hpt_p->GetBinContent(10) << endl;
    cout << "p bin 10 error = " << hpt_p->GetBinError(10) << endl;

    cout << "Pi/K ratio bin 10 content = " << hpt_piK_ratio->GetBinContent(10) << endl;
    cout << "Pi/K ratio bin 10 error = " << hpt_piK_ratio->GetBinError(10) << endl;

    cout << "Pi/K ratio_norm bin 10 content = " << hpt_piK_ratio_norm->GetBinContent(10) << endl;
    cout << "Pi/K ratio_norm bin 10 error = " << hpt_piK_ratio_norm->GetBinError(10) << endl;

}