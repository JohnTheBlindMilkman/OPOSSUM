#include "ParticleSelector.h"

namespace Opossum
{
    ParticleSelector::ParticleSelector(const ParticleSelectorInfo &psInfo) : fPSInfo(psInfo)
    {
    }

    ParticleSelector::~ParticleSelector()
    {
    }

    void ParticleSelector::PerformSelection(EventCandidate &evtCand)
    {
        if (this->SelectEvent(evtCand,fPSInfo))
            if (this->SelectTracks(evtCand,fPSInfo))
                evtCand.SetGoodEvent(true);

    }

    bool ParticleSelector::SelectEvent(EventCandidate &evtCand, const ParticleSelectorInfo &psInfo) const
    {
        if (psInfo.eventCutSet)
        {
            if (!evtCand.Select(psInfo.eventCutSet.value()))
            {
                evtCand.SetGoodEvent(false);
                return false;
            }
        }
        return true;
    }
    bool ParticleSelector::SelectTracks(EventCandidate &evtCand, const ParticleSelectorInfo &psInfo) const
    {
        if (psInfo.trackCutSet)
            return evtCand.SelectTracks(psInfo.trackCutSet.value());
            
        return true;
    }
}