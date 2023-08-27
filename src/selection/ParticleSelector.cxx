#include "ParticleSelector.h"

ParticleSelector::ParticleSelector()
{
    std::cout << "ParticleSelector created" << std::endl;
}

ParticleSelector::~ParticleSelector()
{
}

void ParticleSelector::PerformSelection(EventCandidate &evtCand)
{
    if (this->SelectEvent(evtCand,fEventCutVec))
        if (this->SelectTracks(evtCand,fTrackCutVec))
            evtCand.SetGoodEvent(true);

    std::cout << "ParticleSelector has performed the selection" << std::endl;
}

bool ParticleSelector::SelectEvent(EventCandidate &evtCand, const std::vector<EventCut> &evtCutList) const
{
    for (auto &cut : evtCutList)
        if (cut.IsRejected(evtCand))
        {
            evtCand.SetGoodEvent(false);
            return false;
        }

    return true;
}
bool ParticleSelector::SelectTracks(EventCandidate &evtCand, const std::vector<TrackCut> &trackCutList) const
{
    return evtCand.SelectTracks(trackCutList);
}