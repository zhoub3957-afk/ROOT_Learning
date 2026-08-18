#include<TFile.h>
#include<TH1F.h>
#include<TCanvas.h>
#include<TTree.h>

void lesson10_readTree()
{
    // 打开ROOT文件
    TFile *file = new TFile("practicle.root", "READ");

    // 从文件中读取树
    TTree *tree = (TTree*)file->Get("tree");

    // 定义变量
    double pt;
    // double pt, eta, phi;

    // 将变量与树的分支关联
    tree->SetBranchAddress("pt", &pt);
    // tree->SetBranchAddress("eta", &eta);
    // tree->SetBranchAddress("phi", &phi);

    // 创建一个画布
    TCanvas *c10 = new TCanvas("c10", "Read Tree Data");

    // 创建一个直方图来存储pt数据
    TH1F *hpt = new TH1F("hpt", "Particle pT Distribution from Tree; pT(Gev/c); N(pT)", 100, 0, 10);

    // 遍历树中的所有条目并填充直方图
    // Long64_t nentries = tree->GetEntries();
    for (int i = 0; i < tree->GetEntries(); i++) 
    {
        tree->GetEntry(i);
        hpt->Fill(pt); // Fill the histogram with the pt value from the tree
    }

    // 绘制直方图
    hpt->Draw();

}