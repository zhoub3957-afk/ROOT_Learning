#include<TFile.h>
#include<TH1F.h>
#include<TCanvas.h>
#include<TTree.h>
#include<TF1.h>
#include<TLegend.h>

void lesson11analysisSTAR()
{
    // 打开ROOT文件
    TFile *file = new TFile("star.root", "READ");

    // 从文件中读取树
    TTree *tree = (TTree*)file->Get("EventTree");

    // 定义变量
    double pt, eta, phi;

    // 将变量与树的分支关联
    tree->SetBranchAddress("pt", &pt);
    tree->SetBranchAddress("eta", &eta);
    tree->SetBranchAddress("phi", &phi);

    // 创建一个画布
    TCanvas *c11 = new TCanvas("c11", "Read Tree Data");

    // 创建一个直方图来存储pt数据
    TH1F *hpt = new TH1F("hpt", "pT Distribution from STAR Tree; pT(Gev/c); N(pT)", 100, 0.2, 5);
   
    // 遍历树中的所有条目并填充直方图
    for (int i = 0; i < tree->GetEntries(); i++) 
    {
        tree->GetEntry(i);

        if (pt < 0.2) continue; // Skip negative pt values
        if (abs(eta) > 1.0) continue; // Skip events with |eta| > 1.0


        hpt->Fill(pt); // Fill the histogram with the pt value from the tree

    }

    // 创建拟合函数
    TF1 *fit = new TF1("fit", "[0]*exp(-x/[1])", 0.2, 5); // Define an exponential function
    fit->SetParameters(5000, 0.8); // Set initial parameters for the fit
    hpt->Fit(fit, "R"); // Fit the histogram with the function

    TLegend *legend = new TLegend(0.6, 0.7, 0.9, 0.9);
    legend->AddEntry(hpt, "pT spectrum", "lp");
    legend->AddEntry(fit, "Exponential Fit", "l");

    // 绘制直方图
    hpt->Draw();
    // fit->SetLineColor(kRed);
    // fit->SetLineWidth(2);
    // fit->Draw("SAME");
    legend->Draw();
    c11->SaveAs("STAR_pT_Distribution.pdf");

}
    