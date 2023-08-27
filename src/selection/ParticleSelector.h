#ifndef ParticleSelector_h
    #define ParticleSelector_h

    #include <iostream>

    #include "TString.h"

    #include "EventCandidate.h"
    #include "cuts/EventCut.h"
    #include "cuts/PairCut.h"
    #include "cuts/TrackCut.h"
    #include "../base/Particle.h"

    class ParticleSelector
    {
        public:
            ParticleSelector();
            ~ParticleSelector();

            void PerformSelection(EventCandidate &evtCand);
            void AddCut(TrackCut cut);
            void AddCut(EventCut cut);
            void AddCut(PairCut cut);

        private:
            bool SelectEvent(EventCandidate &evtCand, const std::vector<EventCut> &evtCutList) const;
            bool SelectTracks(EventCandidate &evtCand, const std::vector<TrackCut> &trackCutList) const;

            TString fParticleName;
            EventCandidate fEventCand;
            std::vector<TrackCut> fTrackCutVec;
            std::vector<EventCut> fEventCutVec;
            std::vector<PairCut> fPairCutVec;
    };

    inline void ParticleSelector::AddCut(TrackCut cut) {fTrackCutVec.push_back(cut);};
    inline void ParticleSelector::AddCut(EventCut cut) {fEventCutVec.push_back(cut);};
    inline void ParticleSelector::AddCut(PairCut cut) {fPairCutVec.push_back(cut);};

#endif