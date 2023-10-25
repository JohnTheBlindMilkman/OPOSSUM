#ifndef Analysis_h
    #define Analysis_h

    #include "Result.h"
    #include "../selection/EventCandidate.h"

    class Analysis
    {
        public:
            Analysis();
            virtual ~Analysis() = default;

            Result PerformAnalysis(const EventCandidate &evtCand);
    };

#endif