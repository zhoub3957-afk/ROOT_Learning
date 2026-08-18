#include<TCanvas.h>
#include<TF1.h>

void lesson06()
{
    // 创建画布
    TCanvas *c6 = new TCanvas("c6", "My First Function Plot");

    // 创建一个TF1对象，定义一个函数
    TF1 *f1 = new TF1("f1", "[0]*exp(-x/[1])", 0, 10); // 定义函数 exp(-x) 在区间 [0, 10] 上

    f1->SetParameters(10, 8); // 设置参数 [0] = 10, [1] = 8
    f1->SetTitle("Exponential Function; x; Aexp(-x/T)");
    // f1->SetLineColor(kBlue); // 设置线条颜色为蓝色
    f1->SetLineWidth(2);     // 设置线条宽度

    // 绘制函数
    f1->Draw();

    c6->SaveAs("plots/lesson06.png");
}