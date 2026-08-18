#include<TCanvas.h>
#include<TGraph.h>

void lesson04()
{
    // 创建画布
    TCanvas *c4 = new TCanvas("c4", "Experiment vs Theory");

    // 创建两个TGraph对象
    const int n = 5;
    double x[n] = {1, 2, 3, 4, 5};
    double y1[n] = {10, 20, 15, 30, 25};
    double y2[n] = {12, 18, 17, 28, 27};
 
    TGraph *data = new TGraph(n, x, y1);

    TGraph *model = new TGraph(n, x, y2);
    
    data->SetTitle("Particle Yield;pT (GeV/c);Counts");
    data->SetMarkerStyle(20);  // the style of points
    data->SetMarkerSize(1.5);   // the size of points

    model->SetLineWidth(2); // the width of the line
    model->SetLineStyle(2); // dashed line

    // 绘制图形
    data->Draw("AP"); // A: Axis, P: Points
    model->Draw("L SAME"); // L: Line

    c4->SaveAs("plots/lesson04.png");
}