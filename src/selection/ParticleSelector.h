#ifndef ParticleSelector_h
    #define ParticleSelector_h

    #include "EventCandidate.h"
    #include "../base/Particle.h"

    class ParticleSelector
    {
        public:
            ParticleSelector(Particle &part);
            ~ParticleSelector();

            void PerformSelection(); // add cut list as argument and an .root file as input data ; return the output .root file
    };

#endif