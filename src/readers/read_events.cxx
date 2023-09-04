#include <iostream>
#include "UnigenEventCandidate.h"
#include "UnigenReader.h"
#include "../selection/ParticleSelector.h"
#include "../selection/cuts/eventCuts/JJEventCut.h"
#include "../selection/cuts/trackCuts/JJTrackCut.h"
#include "../selection/cuts/pairCuts/JJPairCut.h"

int main(int argc, char *argv[])
{
    int goodTracks = 0;
    UnigenReader reader("/home/jedkol/Downloads/UniGen/bin","events",1);
    ParticleSelector selector = ParticleSelector(JJEventCut(),JJTrackCut(),JJPairCut());
    UnigenEventCandidate event;

    reader.InitReader();
    while (reader.GetNextEvent(event))
    {
        selector.PerformSelection(event);
        goodTracks += event.GetAcceptedTracks().size();
    }
    reader.CloseReader();

    std::cout << goodTracks << " good tracks selected" << std::endl;

    return 0;
}