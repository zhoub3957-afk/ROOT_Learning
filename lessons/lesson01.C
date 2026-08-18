#include <TCanvas.h>
#include <TH1F.h>

void lesson01()
{

    // 创建画布
    TCanvas *c1 = new TCanvas("c1","My First ROOT Canvas");


    // 创建一个直方图
    TH1F *h1 = new TH1F("h1", "Particle Momentum Distribution", 500, -5, 5);


    // 填充高斯随机数据
    h1->FillRandom("gaus", 100000000);


    // 绘制坐标
    h1->GetXaxis()->SetTitle("pT (GeV/c)");
    h1->GetYaxis()->SetTitle("Counts");

    h1->Draw();

    c1->SaveAs("plots/lesson01.png");

}