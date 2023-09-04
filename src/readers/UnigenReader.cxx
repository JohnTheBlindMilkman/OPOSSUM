#include "UnigenReader.h"

UnigenReader::UnigenReader(const TString &inpDirPath, const TString &treeName, const int &nFiles) : fInpDirPath(inpDirPath), fTreeName(treeName), fNumberOfFiles(nFiles)
{
    fUniEvent = nullptr;
    fInpFileNameBase = "unigen";
    fEntries = 0;
    fCurrentEntry = 0;
    std::cout << "UnigenReader created" << std::endl;
}

UnigenReader::~UnigenReader()
{

}

std::unique_ptr<TChain> UnigenReader::ReadFiles(const TString &inpDirPath, const int &nFiles)
{
    std::unique_ptr<TChain> chain(new TChain(fTreeName));
    for (int i = 0; i < nFiles; i++)
        chain->Add(Form("%s/%s%03d.root",inpDirPath.Data(),fInpFileNameBase.Data(),i));

    std::cout << "UnigenReader added " << nFiles << " files" << std::endl;
    return chain;
}

void UnigenReader::InitReader()
{
    fFileChain = ReadFiles(fInpDirPath,fNumberOfFiles);
    fEntries = fFileChain->GetEntries();
    fFileChain->SetBranchAddress("event",&fUniEvent);
}

bool UnigenReader::GetNextEvent(UnigenEventCandidate &evtCand)
{
    if (fCurrentEntry == fEntries)
        return false;

    fFileChain->GetEntry(fCurrentEntry);
    evtCand = UnigenEventCandidate(fUniEvent);
    
    ++fCurrentEntry;

    return true;
}

void UnigenReader::CloseReader()
{
}