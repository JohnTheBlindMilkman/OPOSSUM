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
            
            void AddTrack(TrackCandidate cand);
            bool IsGoodEvent();
            void SetGoodEvent(bool good);
            bool SelectTracks(const TrackCut &trackCut);
            ROOT::VecOps::RVec<TrackCandidate> GetAcceptedTracks();
            ROOT::VecOps::RVec<TrackCandidate> GetRejectedTracks();


        protected:
            bool fIsGoodEvent; // default = true
            float fB; // in fm
            float fReactionPlaneAngle; // in rad

        private:
            ROOT::VecOps::RVec<TrackCandidate> fAllTracks, fGoodTracks, fBadTracks;

    };

    inline void EventCandidate::AddTrack(TrackCandidate cand) {fAllTracks.push_back(cand);};
    inline bool EventCandidate::IsGoodEvent() {return fIsGoodEvent;};
    inline void EventCandidate::SetGoodEvent(bool good) {fIsGoodEvent = good;};
    inline ROOT::VecOps::RVec<TrackCandidate> EventCandidate::GetAcceptedTracks() {return fGoodTracks;};
    inline ROOT::VecOps::RVec<TrackCandidate> EventCandidate::GetRejectedTracks() {return fBadTracks;};

#endif