#include<TCanvas.h>
#include<TGraphErrors.h>

void lesson05()
{
    // 创建画布
    TCanvas *c5 = new TCanvas("c5", "My First Graph with Errors");

    // 创建一个TGraphErrors对象
    const int n = 5;
    double x[n] = {1, 2, 3, 4, 5};
    double y[n] = {10, 20, 15, 30, 25};
    double ex[n] = {0, 0, 0, 0, 0}; // x误差
    double ey[n] = {2, 3, 2.5, 4, 3}; // y误差

    TGraphErrors *gr = new TGraphErrors(n, x, y, ex, ey);
    gr->SetTitle("Particle Yield with Errors; pT (GeV/c); Counts");
    gr->SetMarkerStyle(21);  // the style of points
    gr->SetMarkerSize(1.5);   // the size of points

    // 绘制图形
    gr->Draw("AP"); // A: Axis, L: Line, P: Points

    c5->SaveAs("lesson05.png");
}