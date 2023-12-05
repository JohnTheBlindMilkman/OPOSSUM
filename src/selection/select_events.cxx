#include <iostream>

#include "ParticleSelector.h"

using namespace Opossum;

int main(/* int argc, char *argv[] */)
{
    ConfigParser parser("/home/jedkol/Downloads/OPOSSUM/config.json");
    ParticleSelector selector = ParticleSelector(parser.PassSelectionInformation());

    EventCandidate evtCand = EventCandidate();

    selector.PerformSelection(evtCand);

    return 0;
}