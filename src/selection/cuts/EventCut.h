#ifndef EventCut_h
    #define EventCut_h

    #include "../EventCandidate.h"

    class EventCut
    {
        public:
            EventCut();
            virtual ~EventCut() = default;

            bool IsRejected(const EventCandidate &evtCand) const;
    };

#endif