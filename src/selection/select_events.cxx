#include <iostream>

#include "cuts/eventCuts/JJEventCut.h"
#include "cuts/trackCuts/JJTrackCut.h"
#include "ParticleSelector.h"

int main(int argc, char *argv[])
{
    JJEventCut evtCut = JJEventCut();
    JJTrackCut trckCut = JJTrackCut();

    ParticleSelector selector = ParticleSelector();
    selector.AddCut(evtCut);
    selector.AddCut(trckCut);

    EventCandidate evtCand = EventCandidate();

    selector.PerformSelection(evtCand);

    return 0;
}