#include "EventCandidate.h"

namespace Opossum
{
    EventCandidate::EventCandidate()
    {
    }

    bool EventCandidate::SelectTracks(const std::unordered_map<TrackObservable,CutEntry> &trackCut)
    {
        for (auto &track : fAllTracks)
        {
            if (track.Select(trackCut))
                fGoodTracks.push_back(track);
            else
                fBadTracks.push_back(track);
        }

        if (fGoodTracks.size())
            return true;
        else
            return false;
    }
} // namespace Opossum