/**
 * @file UnigenParticleCandidate.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Adapter class for converting the UNIGEN format to ParticleCandidate format.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef UnigenParticleCandidate_h
    #define UnigenParticleCandidate_h

    #include "UParticle.h"
    #include "../selection/TrackCandidate.h"

    // adapter for UParticle class
    class UnigenParticleCandidate : public TrackCandidate
    {
        public:
            /**
             * @brief Construct a new Unigen Particle Candidate object
             * 
             * @param particle 
             */
            UnigenParticleCandidate(UParticle *particle);
            /**
             * @brief Destroy the Unigen Particle Candidate object
             * 
             */
            ~UnigenParticleCandidate();
    };

#endif