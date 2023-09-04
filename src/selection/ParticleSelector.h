#ifndef ParticleSelector_h
    #define ParticleSelector_h

    #include <iostream>

    #include "TString.h"

    #include "EventCandidate.h"
    #include "cuts/EventCut.h"
    #include "cuts/PairCut.h"
    #include "cuts/TrackCut.h"

    class ParticleSelector
    {
        public:
            ParticleSelector(const EventCut &evtCut, const TrackCut &trckCut, const PairCut &prCut);
            ~ParticleSelector();

            void PerformSelection(EventCandidate &evtCand);

        private:
            bool SelectEvent(EventCandidate &evtCand, const EventCut &evtCut) const;
            bool SelectTracks(EventCandidate &evtCand, const TrackCut &trackCut) const;

            TString fParticleName;
            EventCandidate fEventCand;
            EventCut fEventCut;
            TrackCut fTrackCut;
            PairCut fPairCut;
    };

#endif