#ifndef FemtoAnalysis_h
    #define FemtoAnalysis_h

    #include "../Analysis.h"
    #include "../Result.h"
    #include "../../selection/EventCandidate.h"

    class FemtoAnalysis : Analysis
    {
        public:
            FemtoAnalysis(/* args */);
            ~FemtoAnalysis();

            Result PerformAnalysis(const EventCandidate &evtCand);

        private:
    };
    
#endif