#define LHEF_cxx
#include "LHEF.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <iotream>

using namespace std;

void LHEF::Loop(char* name)
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}

int main(int argc, char **argv){
    if (argc != 3)
    {
        cout << "Too few arguments!" << endl;
        cout << "Proper form of input:" << endl;
        cout << "./program\tDATAFILE.root\tHISTOGRAMFILE.root" << endl;
        return 1;
    }
    cout << argv[1] << "\t" << argv[2] << endl;

    TChain *chain = new TChain("LHEF");
    chain->Add(argv[1]);

    LHEF obiekt(chain);
    obiekt.Loop(argv[2]);

    return 0;
}