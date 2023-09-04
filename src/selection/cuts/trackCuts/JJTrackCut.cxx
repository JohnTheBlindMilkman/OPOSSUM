#include "JJTrackCut.h"

JJTrackCut::JJTrackCut()
{
}

JJTrackCut::~JJTrackCut()
{

}

bool JJTrackCut::IsRejected(const TrackCandidate &trackCand) const
{
    if (trackCand.GetPid() != 2212)
        return true;
    if (abs(trackCand.GetMomentum().Rapidity()) > 0.5)
        return true;

    return false;
}