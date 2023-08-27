#ifndef JJTrackCut_h
    #define JJTrackCut_h

    #include <iostream>

    #include "../../TrackCandidate.h"
    #include "../TrackCut.h"

    class JJTrackCut : public TrackCut
    {
        public:
            JJTrackCut();
            ~JJTrackCut();

            bool IsRejected(const TrackCandidate &trackCand) const;
    };

#endif