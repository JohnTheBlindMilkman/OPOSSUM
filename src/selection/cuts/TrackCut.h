#ifndef TrackCut_h
    #define TrackCut_h

    #include "../TrackCandidate.h"

    class TrackCut
    {
        public:
            TrackCut();
            virtual ~TrackCut() = default;

            bool IsRejected(const TrackCandidate &trackCand) const;
    };

#endif