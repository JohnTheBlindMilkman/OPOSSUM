#include "JJEventCut.h"

JJEventCut::JJEventCut()
{
    std::cout << "JJEventCut created" << std::endl;
}

JJEventCut::~JJEventCut()
{

}

bool JJEventCut::IsRejected(const EventCandidate &evtCand) const
{
    return false;
}