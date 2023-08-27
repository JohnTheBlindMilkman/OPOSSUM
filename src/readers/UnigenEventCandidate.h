#ifndef UnigenEventCandidate_h
    #define UnigenEventCandidate_h

    #include "../selection/EventCandidate.h"
    #include "UEvent.h"

    // adapter for UEvent class
    class UnigenEventCandidate : public EventCandidate
    {
        public:
            UnigenEventCandidate(UEvent *event);
            ~UnigenEventCandidate();

        private:
            UEvent *fEvent;
    };

#endif