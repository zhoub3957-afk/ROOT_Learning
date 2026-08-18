#include<TFile.h>
#include<TH1F.h>
#include<TRandom3.h>

void lesson09_createFile()
{
    // 创建一个ROOT文件
    TFile *file = new TFile("test.root", "RECREATE"); //recreate

    // 创建一个直方图
    TH1F *hpt = new TH1F("hpt", "Particle pT Distribution", 100, 0, 10);

    TRandom3 random;

    for (int i = 0; i < 10000; i++) 
    {
        double pt = random.Exp(2); // Generate a random pt from an exponential distribution
        hpt->Fill(pt); // Fill the histogram with the generated pt
    }

    // 将直方图写入文件
    hpt->Write();

    // 关闭文件
    file->Close();
}