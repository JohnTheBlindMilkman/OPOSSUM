/**
 * @file UnigenEventCandidate.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Adapter class for converting the UNIGEN format to EventCandidate format.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef UnigenEventCandidate_h
    #define UnigenEventCandidate_h

    #include "../selection/EventCandidate.h"
    #include "UEvent.h"
    #include "UnigenParticleCandidate.h"

    // adapter for UEvent class
    class UnigenEventCandidate : public EventCandidate
    {
        public:
            /**
             * @brief Construct a new Unigen Event Candidate object
             * 
             */
            UnigenEventCandidate() = default;
            /**
             * @brief Construct a new Unigen Event Candidate object
             * 
             * @param event 
             */
            UnigenEventCandidate(UEvent *event);
            /**
             * @brief Destroy the Unigen Event Candidate object
             * 
             */
            ~UnigenEventCandidate();

        private:
            UEvent *fEvent;

    };

#endif