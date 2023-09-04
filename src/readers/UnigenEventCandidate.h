#ifndef UnigenEventCandidate_h
    #define UnigenEventCandidate_h

    #include "../selection/EventCandidate.h"
    #include "UEvent.h"
    #include "UnigenParticleCandidate.h"

    // adapter for UEvent class
    class UnigenEventCandidate : public EventCandidate
    {
        public:
            UnigenEventCandidate() = default;
            UnigenEventCandidate(UEvent *event);
            ~UnigenEventCandidate();

        private:
            UEvent *fEvent;

    };

#endif