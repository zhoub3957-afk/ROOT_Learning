#include<TH1F.h>
#include<TCanvas.h>
#include<iostream>

using namespace std;

void lesson15()
{
    TH1F *hPi = new TH1F("hPi", "Pion", 10, 0, 10);
    TH1F *hK = new TH1F("hK", "Kaon", 10, 0, 10);
    hPi->Sumw2();
    hK->Sumw2();

    for(int i = 0; i < 1296; i++)
    {
        hPi->Fill(1.0, 1.0);
    }

    for(int i = 0; i < 588; i++)
    {
        hK->Fill(1.0);
    }

    TH1F *hRatio = (TH1F*)hPi->Clone("hRatio");
    hRatio->Divide(hK);

    cout << "Pion content = " << hPi->GetBinContent(2) << endl;
    cout << "Pion error = " << hPi->GetBinError(2) << endl;

    cout << "Kaon content = " << hK->GetBinContent(2) << endl;
    cout << "Kaon error = " << hK->GetBinError(2) << endl;

    cout << "Ratio content = " << hRatio->GetBinContent(2) << endl;
    cout << "Ratio error = " << hRatio->GetBinError(2) << endl;

    TCanvas *c15 = new TCanvas("c15", "Ratio of Histograms");
    hRatio->Draw();

    c15->SaveAs("lesson15.png");
}