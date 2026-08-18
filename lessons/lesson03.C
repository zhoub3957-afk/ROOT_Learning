#include<TCanvas.h>
#include<TH1F.h>
#include<TRandom3.h>
#include<iostream>

using namespace std;

void lesson03()
{
    // 创建画布
    TCanvas *c3 = new TCanvas("c3","pT distribution");

    // 创建一个直方图
    TH1F *h3 = new TH1F("h3", "Particle pT Distribution", 100, 0, 10);

    TRandom3 random;

    for (int i = 0; i < 100000; i++) 
    {
        double pT = random.Gaus(3, 0.2); // Generate a random pT from a Gaussian distribution
        h3->Fill(pT); // Fill the histogram with the generated pT
    }

   

    h3->GetXaxis()->SetTitle("pT (GeV/c)");
    h3->GetYaxis()->SetTitle("N(pT)");

    h3->Draw();


    cout << "Entries: " << h3->GetEntries() << endl;
    cout << "Mean: " << h3->GetMean() << endl;
    cout << "Std Dev: " << h3->GetStdDev() << endl;
    // cout << "RMS: " << h3->GetRMS() << endl;
    cout << "pT > 2.5 GeV/c = " << h3->Integral(25, 35) << endl;
    cout << "Bin Content (30): " << h3->GetBinContent(30) << endl;

    c3->SaveAs("plots/lesson03.png");

}