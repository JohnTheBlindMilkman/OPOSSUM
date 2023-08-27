#ifndef JJEventCut_h
    #define JJEventCut_h

    #include <iostream>

    #include "../../EventCandidate.h"
    #include "../EventCut.h"

    class JJEventCut : public EventCut
    {
        public:
            JJEventCut();
            ~JJEventCut();

            bool IsRejected(const EventCandidate &evtCand) const;
    };

#endif