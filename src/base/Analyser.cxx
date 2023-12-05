#include "Analyser.h"

namespace Opossum
{
    Analyser::Analyser(const Analysis analysis, const ParticleSelector &selector, const TString &inpDirPath, const TString &treeName, const int &nFiles) : fReader(inpDirPath,treeName,nFiles), fSelector(selector), fAnalysis(analysis), fDoNext(false)
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
}