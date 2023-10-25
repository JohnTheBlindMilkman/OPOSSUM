#include "Analyser.h"

Analyser::Analyser(const Analysis analysis, const ParticleSelector &selector, const TString &inpDirPath, const TString &treeName, const int &nFiles) : fAnalysis(analysis), fSelector(selector), fReader(inpDirPath,treeName,nFiles), fDoNext(false)
{
}

void Analyser::Init()
{
    fReader.InitReader();
}

bool Analyser::Next()
{
    fDoNext = fReader.GetNextEvent(fEvtCand);
    fSelector.PerformSelection(fEvtCand);
    fAnalysis.PerformAnalysis(fEvtCand);

    return fDoNext;
}

void Analyser::Finish()
{
    fReader.CloseReader();
}

Result Analyser::DoAnalysis(int threads)
{
    this->Init();
    while (this->Next());
    this->Finish();

    return fResult;
}