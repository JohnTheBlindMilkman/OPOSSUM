#ifndef JJPairCut_h
    #define JJPairCut_h

    #include <iostream>

    #include "../../TrackCandidate.h"
    #include "../PairCut.h"

    class JJPairCut : public PairCut
    {
        public:
            JJPairCut() = default;
            ~JJPairCut() = default;

            bool IsRejected(const TrackCandidate &trackCand1, const TrackCandidate &trackCand2) const;
    };

#endif