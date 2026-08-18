#include<TFile.h>
#include<TTree.h>
#include<TRandom3.h>

void lesson10_createTree()
{
    // 创建一个ROOT文件
    TFile *file = new TFile("data/practicle.root", "RECREATE");

    // 创建一个TTree对象
    TTree *tree = new TTree("tree", "Practice Tree");

    // 定义变量
    double pt, eta, phi;

    // 将变量与树的分支关联
    tree->Branch("pt", &pt, "pt/D");
    tree->Branch("eta", &eta, "eta/D");
    tree->Branch("phi", &phi, "phi/D");

    TRandom3 random;

    // 填充树的数据
    for (int i = 0; i < 10000; i++) 
    {
        pt = random.Exp(2); // Generate a random number from an exponential distribution
        eta = random.Gaus(0, 1);
        phi = random.Uniform(-3.14, 3.14);
        tree->Fill(); // Fill the tree with the generated data
    }

    // 将树写入文件
    tree->Write();

    // 关闭文件
    file->Close();
}