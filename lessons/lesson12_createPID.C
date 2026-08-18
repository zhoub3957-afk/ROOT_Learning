#include<TFile.h>
#include<TTree.h>
#include<TRandom3.h>
#include<TMath.h>

void lesson12_createPID()
{
    // 创建一个ROOT文件
    TFile *file = new TFile("data/PID_simulation.root", "RECREATE");

    // 创建一个TTree对象
    TTree *tree = new TTree("ParticleTree", "Simulated Particle Identification Data");

    // 定义变量
    double pt, eta, phi;
    int pid; // Particle ID: 211 for pi+, 321 for K+, 2212 for proton

    tree->Branch("pt", &pt, "pt/D");
    tree->Branch("eta", &eta, "eta/D");
    tree->Branch("phi", &phi, "phi/D");
    tree->Branch("pid", &pid, "pid/I");

    TRandom3 random;

    // 填充树的数据
    for (int i = 0; i < 100000; i++) 
    {
        pt = random.Exp(0.8);
        eta = random.Gaus(0, 1);
        phi = random.Uniform(0, 2 * TMath::Pi());
        double r = random.Uniform();
        
        if (r < 0.6) 
        {
            pid = 211; // pi+
        } 
        else if (r < 0.85)
       {
            pid = 321; // K+
        } 
        else 
        {
            pid = 2212; // proton
        }
        tree->Fill();
        
    }

    // 写入文件
    file->Write();
    file->Close();
}