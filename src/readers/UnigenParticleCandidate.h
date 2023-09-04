#ifndef UnigenParticleCandidate_h
    #define UnigenParticleCandidate_h

    #include "UParticle.h"
    #include "../selection/TrackCandidate.h"

    // adapter for UParticle class
    class UnigenParticleCandidate : public TrackCandidate
    {
        public:
            UnigenParticleCandidate(UParticle *particle);
            ~UnigenParticleCandidate();
    };

#endif