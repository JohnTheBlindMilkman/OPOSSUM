#include <iostream>
#include <thread>
#include <chrono>
#include "../readers/UnigenEventCandidate.h"
#include "../readers/UnigenReader.h"
#include "../selection/ParticleSelector.h"
#include "../selection/PairCandidate.h"
#include "femto/TPIWeightGenerator.h"
#include "../utils/indicators.hpp"

using namespace Opossum;

int main(/* int argc, char *argv[] */)
{
    long unsigned int nEvents = 0;
    int nCounter = 100;
    long unsigned int goodTracks = 0;
    std::pair<float,long unsigned int> avgWeight = {0.,0};
    std::size_t entries;
    UnigenReader reader("/home/jedkol/Downloads/UniGen/bin","events",1);
    ConfigParser parser("/home/jedkol/Downloads/OPOSSUM/config.json");
    ParticleSelector selector(parser.PassSelectionInformation());
    UnigenEventCandidate event;
    PairCandidate pair;
    TPIWeightGenerator weightGen;

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
        goodTracks += event.GetAcceptedTracks().size();
        if (event.GetAcceptedTracks().size() > 1)
        {
            for (auto &track1 : event.GetAcceptedTracks())
                for (auto &track2 : event.GetAcceptedTracks())
                {
                    pair = PairCandidate(track1,track2);
                    avgWeight.first += weightGen.CalculateWeight(pair);
                    ++avgWeight.second;
                }
        }
    }
    bar.mark_as_completed();
    reader.CloseReader();

    std::cout << goodTracks << " good tracks selected\n";
    std::cout << avgWeight.first / avgWeight.second << " average weight\n";

    indicators::show_console_cursor(true);
}