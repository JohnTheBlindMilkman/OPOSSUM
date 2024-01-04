#include <iostream>
#include "Analyser.h"
#include "analyses/FemtoAnalysis.h"
#include "../selection/ParticleSelector.h"
#include "../readers/UnigenEventCandidate.h"
#include "../readers/UnigenReader.h"
#include "../selection/PairCandidate.h"
#include "femto/TPIWeightGenerator.h"
#include "../utils/indicators.hpp"

using namespace Opossum;

int main(void)
{
    long unsigned int nEvents = 0;
    int nCounter = 100;
    std::size_t entries;
    UnigenReader reader("/home/jedkol/Downloads/UniGen/bin","events",1);
    ConfigParser parser("/home/jedkol/Downloads/OPOSSUM/config.json");
    ParticleSelector selector(parser.PassSelectionInformation());
    UnigenEventCandidate event;
    FemtoAnalysis analysis;

    indicators::show_console_cursor(false);

    indicators::BlockProgressBar bar
    {
        indicators::option::BarWidth{80}, 
        indicators::option::ForegroundColor{indicators::Color::blue},
        indicators::option::FontStyles{std::vector<indicators::FontStyle>{indicators::FontStyle::bold}},
        indicators::option::ShowElapsedTime{true},
        indicators::option::ShowRemainingTime{true}
    };

    entries = reader.InitReader();
    analysis.InitAnalysis();
    bar.set_option(indicators::option::MaxProgress{entries});

    while (reader.GetNextEvent(event))
    {
        ++nEvents;
        if (--nCounter == 0)
        {
            bar.set_progress(nEvents);
            nCounter = 100;
        }

        selector.PerformSelection(event);
        analysis.PerformAnalysis(event);
    }

    bar.mark_as_completed();
    analysis.FinishAnalysis();
    reader.CloseReader();
}