#ifndef EventCandidate_h
    #define EventCandidate_h

    #include <iostream>

    #include "TrackCandidate.h"
    #include "cuts/TrackCut.h"

    #include "ROOT/RVec.hxx"

    class EventCandidate
    {
        public:
            EventCandidate();
            virtual ~EventCandidate() = default;
            
            bool IsGoodEvent();
            void SetGoodEvent(bool good);
            bool SelectTracks(const std::vector<TrackCut> &trackCutList);
            ROOT::VecOps::RVec<TrackCandidate> GetAcceptedTracks();
            ROOT::VecOps::RVec<TrackCandidate> GetRejectedTracks();


        private:
            bool fIsGoodEvent; // default = true
            float fB; // in fm
            int fNParticipants;
            float fReactionPlaneAngle; // in rad
            ROOT::VecOps::RVec<TrackCandidate> fAllTracks, fGoodTracks, fBadTracks;

    };

    inline bool EventCandidate::IsGoodEvent() {return fIsGoodEvent;};
    inline void EventCandidate::SetGoodEvent(bool good) {fIsGoodEvent = good;};
    inline ROOT::VecOps::RVec<TrackCandidate> EventCandidate::GetAcceptedTracks() {return fGoodTracks;};
    inline ROOT::VecOps::RVec<TrackCandidate> EventCandidate::GetRejectedTracks() {return fBadTracks;};

#endif