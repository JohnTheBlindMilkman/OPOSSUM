#include "FemtoAnalysis.h"

namespace Opossum
{
    FemtoAnalysis::FemtoAnalysis(/* args */)
    {
    }

    FemtoAnalysis::~FemtoAnalysis()
    {
    }

    void FemtoAnalysis::InitAnalysis() const
    {
    }

    GenericResult FemtoAnalysis::PerformAnalysis(const EventCandidate &evtCand)
    {
        auto pairs = fEvtMixer.MakePairs(evtCand.GetAcceptedTracks());

        for(const auto &pair : pairs)
        {
            fCorrFunc1D.AddPair(pair,fWeightGen.CalculateWeight(pair));
        }

        return GenericResult();
    }

    void FemtoAnalysis::FinishAnalysis() const
    {
    }
}

