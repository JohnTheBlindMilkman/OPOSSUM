#include <iostream>

#include "cuts/eventCuts/JJEventCut.h"
#include "cuts/trackCuts/JJTrackCut.h"
#include "cuts/pairCuts/JJPairCut.h"
#include "ParticleSelector.h"

int main(int argc, char *argv[])
{
    ParticleSelector selector = ParticleSelector(JJEventCut(),JJTrackCut(),JJPairCut());

    EventCandidate evtCand = EventCandidate();

    selector.PerformSelection(evtCand);

    return 0;
}