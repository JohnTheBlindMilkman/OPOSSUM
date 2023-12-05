/**
 * @file ParticleSelector.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Main class for performing the particle selection. Utilises the selection.json configuration file.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ParticleSelector_h
    #define ParticleSelector_h

    #include <iostream>

    #include "TString.h"

    #include "EventCandidate.h"
    #include "../utils/ConfigParser.h"

    namespace Opossum
    {
        class ParticleSelector
        {
            public:
                /**
                 * @brief Construct a new Particle Selector object
                 * 
                 * @param psInfo 
                 */
                ParticleSelector(const ParticleSelectorInfo &psInfo);
                /**
                 * @brief Destroy the Particle Selector object
                 * 
                 */
                ~ParticleSelector();

                /**
                 * @brief When evoked, will set the isGoodEvent flag based on the selection criteria and will perform the same selection on the tracks which are assigned the event.
                 * 
                 * @param evtCand 
                 */
                void PerformSelection(EventCandidate &evtCand);

            private:
                /**
                 * @brief Perform selectoin on the event. Returns true if accepted and false otherwise.
                 * 
                 * @param evtCand 
                 * @param evtCut 
                 * @return true 
                 * @return false 
                 */
                bool SelectEvent(EventCandidate &evtCand, const ParticleSelectorInfo &psInfo) const;
                /**
                 * @brief Perform selection on the tracks. Pass the TrackCut object to the EventCandidate object and evoke SelectTracks method.
                 * 
                 * @param evtCand 
                 * @param trackCut 
                 * @return true 
                 * @return false 
                 */
                bool SelectTracks(EventCandidate &evtCand, const ParticleSelectorInfo &psInfo) const;

                std::string fParticleName;
                EventCandidate fEventCand;
                ParticleSelectorInfo fPSInfo;
        };
    }

#endif