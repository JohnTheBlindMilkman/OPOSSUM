#ifndef UnigenEventCandidate_h
    #define UnigenEventCandidate_h

    #include "../selection/EventCandidate.h"
    #include "UEvent.h"

    // adapter for UEvent class
    class UnigenEventCandidate : public EventCandidate
    {
        public:
            UnigenEventCandidate() = default;
            UnigenEventCandidate(UEvent *event);
            ~UnigenEventCandidate();

            bool IsGoodEvent();
            void SetGoodEvent(bool good);
            bool SelectTracks(const std::vector<TrackCut> &trackCutList);
            ROOT::VecOps::RVec<TrackCandidate> GetAcceptedTracks();
            ROOT::VecOps::RVec<TrackCandidate> GetRejectedTracks();

        private:
            UEvent *fEvent;
            bool fIsGoodEvent; // default = true
            float fB; // in fm
            int fNParticipants;
            float fReactionPlaneAngle; // in rad
            ROOT::VecOps::RVec<TrackCandidate> fAllTracks, fGoodTracks, fBadTracks; 
    };

#endif