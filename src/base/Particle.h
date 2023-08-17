#ifndef particle_h
    #define particle_h

    #include "TString.h"

    class Particle
    {
        public:
            Particle();
            ~Particle();

        private:
            TString fName;
            int fPid;
            double fMass;
    };

#endif