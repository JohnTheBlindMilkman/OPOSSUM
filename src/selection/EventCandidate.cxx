#include "EventCandidate.h"

EventCandidate::EventCandidate()
{
    std::cout << "EventCandidate created" << std::endl;
}

bool EventCandidate::SelectTracks(const std::vector<TrackCut> &trackCutList)
{
    bool isGood = true;
    for (auto &track : fAllTracks)
    {
        isGood = true;
        for (auto &cut : trackCutList)
            if (cut.IsRejected(track))
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