#include "Analyser.h"

namespace Opossum
{
    Analyser::Analyser(const Analysis &analysis, const ParticleSelector &selector, const TString &inpDirPath, const TString &treeName, const int &nFiles) : fReader(inpDirPath,treeName,nFiles), fSelector(selector), fAnalysis(analysis), fDoNext(false)
    {
    }

    void Analyser::Init()
    {
        fReader.InitReader();
        fAnalysis.InitAnalysis();
    }

    bool Analyser::Next()
    {
        fDoNext = fReader.GetNextEvent(fEvtCand);
        if (fDoNext)
        {
            fSelector.PerformSelection(fEvtCand);
            fAnalysis.PerformAnalysis(fEvtCand);  // how do I select pairs? add pair vec to the fEvtCand? pass fSelector to fAnalysis?
            // fAnalysis.PerformAnalyis(fEvtCand) with forwarded fSelector
            // if all we're gonna do is the analysis, there is no point in doin the selection separately
            // particle selection is a part of every      
        }

        return fDoNext;
    }

    void Analyser::Finish()
    {
        fAnalysis.FinishAnalysis();
        fReader.CloseReader();
    }

    void Analyser::DoAnalysis(int threads)
    {
        this->Init();
        while (this->Next());
        this->Finish();
    }
}