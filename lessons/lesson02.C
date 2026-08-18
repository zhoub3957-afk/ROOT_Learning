#include <TCanvas.h>
#include <TH1F.h>


void lesson02()
{

    // 创建画布
    TCanvas *c2 = new TCanvas("c2", "My Second ROOT Canvas");


    // 创建一个直方图
    TH1F *h2 = new TH1F("h2", "Particle pT Distribution", 50, 0, 10);

    double pt_values[] = {1.2, 2.5, 3.1, 4.7, 5.0, 6.3, 7.8, 8.9, 9.5};

    int num_values = sizeof(pt_values) / sizeof(pt_values[0]);

    for (int i = 0; i < num_values; i++) 
    {
        h2->Fill(pt_values[i]);
    }



    // TRandom3 random;

    // for (int i = 0; i < 10000; i++) 
    // {
    //     double pt = random.Gaus(3, 1); // Generate a random pt from a Gaussian distribution
    //     h1->Fill(pt); // Fill the histogram with the generated pt
    // }


    // h1->Fill(-2);
    // h1->Fill(1);
    // h1->Fill(2);

    // h1->Fill(3,3);

    // h1->Fill(5,10);


    h2->Draw();

    c2->SaveAs("plots/lesson02.png");

}