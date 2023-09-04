#include "ParticleSelector.h"

ParticleSelector::ParticleSelector(const EventCut &evtCut, const TrackCut &trckCut, const PairCut &prCut) : fEventCut(evtCut), fTrackCut(trckCut), fPairCut(prCut)
{
}

ParticleSelector::~ParticleSelector()
{
}

void ParticleSelector::PerformSelection(EventCandidate &evtCand)
{
    if (this->SelectEvent(evtCand,fEventCut))
        if (this->SelectTracks(evtCand,fTrackCut))
            evtCand.SetGoodEvent(true);

}

bool ParticleSelector::SelectEvent(EventCandidate &evtCand, const EventCut &evtCut) const
{
    if (evtCut.IsRejected(evtCand))
    {
        evtCand.SetGoodEvent(false);
        return false;
    }

    return true;
}
bool ParticleSelector::SelectTracks(EventCandidate &evtCand, const TrackCut &trackCut) const
{
    return evtCand.SelectTracks(trackCut);
}