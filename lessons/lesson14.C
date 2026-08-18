#include<TH1F.h>
#include<TCanvas.h>
#include<iostream>

using namespace std;

void lesson14()
{
    TH1F *h = new TH1F("h", "Scale and Error;x;Counts", 10, 0, 10);
    h->Sumw2();

    for(int i=0; i<100; i++)
    {
        h->Fill(1.0);
    }

    cout << "Before scaling: " << endl;
    cout << "Content = " << h->GetBinContent(2) << endl;
    cout << "Error = " << h->GetBinError(2) << endl;

    h->Scale(2.0);
    cout << "After scaling: " << endl;
    cout << "Content = " << h->GetBinContent(2) << endl;
    cout << "Error = " << h->GetBinError(2) << endl;

    TCanvas *c = new TCanvas("c", "Scale and Error");
    h->Draw();
    c->SaveAs("plots/lesson14.png");

}