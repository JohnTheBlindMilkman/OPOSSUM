#include "JJTrackCut.h"

JJTrackCut::JJTrackCut()
{
    std::cout << "JJTrackCut created" << std::endl;
}

JJTrackCut::~JJTrackCut()
{

}

bool JJTrackCut::IsRejected(const TrackCandidate &trackCand) const
{
    return false;
}