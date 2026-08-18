#include<TFile.h>
#include<TH1F.h>

void lesson09_readFile()
{
    // 打开ROOT文件
    TFile *file = new TFile("data/test.root", "READ");

    // 从文件中读取直方图
    TH1F *hpt = (TH1F*)file->Get("hpt");

    // 绘制直方图
    hpt->Draw();


}