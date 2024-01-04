/**
 * @file PairCandidate.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Base class for storing pair object. It defines the pair format for the whole program.
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PairCandidate_h
    #define PairCandidate_h

    #include "GenericCandidate.h"
    #include "TrackCandidate.h"

    namespace Opossum
    {
        class PairCandidate : public GenericCandidate<PairObservable>
        {
            private:
                TrackCandidate fTrack1, fTrack2;

                /**
                 * @brief Calculate the opening angle between two tracks. Same implementation as in TLorenzVector from CERN ROOT
                 * 
                 * @param particle1 
                 * @param particle2 
                 * @return float 
                 */
                float CalculateOpeningAngle(TrackCandidate &particle1, TrackCandidate &particle2) const;

                void CFKinematics();
                
            public:
                /**
                 * @brief Construct a new Pair Candidate object
                 * 
                 */
                PairCandidate() = default;
                /**
                 * @brief Construct a new Pair Candidate object
                 * 
                 * @param particle1 
                 * @param particle2 
                 */
                PairCandidate(const TrackCandidate &particle1, const TrackCandidate &particle2);
                /**
                 * @brief Destroy the Pair Candidate object
                 * 
                 */
                virtual ~PairCandidate() = default;
                /**
                 * @brief Get the Tracks that constitute the pair object
                 * 
                 * @return std::pair<TrackCandidate,TrackCandidate> 
                 */
                std::pair<TrackCandidate,TrackCandidate> GetTracks() const;
                
        };

        inline std::pair<TrackCandidate,TrackCandidate> PairCandidate::GetTracks() const {return std::make_pair(fTrack1,fTrack2);}
    }

#endif