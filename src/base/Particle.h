#ifndef particle_h
    #define particle_h

    #include "TString.h"

    class Particle
    {
        public:
            Particle();
            ~Particle();

            TString GetName() const;

        private:
            TString fName;
            int fPid;
            double fMass;
    };

    inline TString Particle::GetName() const {return fName;};

#endif