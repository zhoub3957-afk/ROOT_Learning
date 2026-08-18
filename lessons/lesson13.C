#include<TH1F.h>
#include<TCanvas.h>
#include<iostream>

using namespace std;

void lesson13()
{
    TH1F *h = new TH1F("h", "Weighted Histogram; x; Counts", 10, 0, 10);
    h->Sumw2();

    h->Fill(1.0, 1.0);
    h->Fill(1.0, 2.0);
    h->Fill(1.0, 0.5);

    cout << "Content = " << h->GetBinContent(2) << endl;
    cout << "Error = " << h->GetBinError(2) << endl;

    TCanvas *c = new TCanvas("c", "Weighted Histogram");
    h->Draw();

    c->SaveAs("lesson13.png");

    
}