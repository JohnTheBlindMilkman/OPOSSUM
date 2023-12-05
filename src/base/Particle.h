/**
 * @file Particle.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Depricated class - to be modified or removed.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef particle_h
    #define particle_h

    #include "TString.h"

    namespace Opossum
    {
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
    }

#endif