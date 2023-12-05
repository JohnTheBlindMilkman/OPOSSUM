#include <iostream>
#include "UnigenEventCandidate.h"
#include "UnigenReader.h"
#include "../selection/ParticleSelector.h"

using namespace Opossum;

int main(/* int argc, char *argv[] */)
{
    long unsigned int nEvents = 0;
    int nCounter = 100;
    std::size_t goodTracks = 0;
    UnigenReader reader("/home/jedkol/Downloads/UniGen/bin","events",1);
    ConfigParser parser("/home/jedkol/Downloads/OPOSSUM/config.json");
    ParticleSelector selector = ParticleSelector(parser.PassSelectionInformation());
    UnigenEventCandidate event;

    reader.InitReader();
    while (reader.GetNextEvent(event))
    {
        ++nEvents;
        if (--nCounter == 0)
        {
            std::cout << "Event: " << nEvents << "\n";
            nCounter = 100;
        }
        selector.PerformSelection(event);
        goodTracks += event.GetAcceptedTracks().size();
    }
    reader.CloseReader();

    std::cout << goodTracks << " good tracks selected" << std::endl;

    return 0;
}