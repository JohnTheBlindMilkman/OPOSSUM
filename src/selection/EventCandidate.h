#ifndef EventCandidate_h
    #define EventCandidate_h

    #include "TrackCandidate.h"

    #include "ROOT/RVec.hxx"

    class EventCandidate
    {
        public:
            EventCandidate();
            ~EventCandidate();
            
            ROOT::VecOps::RVec<TrackCandidate> GetAcceptedTracks();
            ROOT::VecOps::RVec<TrackCandidate> GetRejectedTracks();

        private:
            float fB; // in fm
            int fNParticipants;
            float fReactionPlaneAngle; // in rad
    };

#endif