#include "EventCandidate.h"

EventCandidate::EventCandidate()
{
}

bool EventCandidate::SelectTracks(const TrackCut &trackCut)
{
    bool isGood = true;
    for (auto &track : fAllTracks)
    {
        isGood = true;
        if (trackCut.IsRejected(track))
        {
            isGood = false;
            fBadTracks.push_back(track);
            break;
        }

        if (isGood)
            fGoodTracks.push_back(track);
    }

    if (fGoodTracks.size())
        return true;
    else
        return false;
}