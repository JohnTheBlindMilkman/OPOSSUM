/**
 * @file TrackCandidate.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Base class for storing track object. It defines the track format for the whole program.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TrackCandidate_h
    #define TrackCandidate_h

    #include "Math/LorentzVector.h"

    class TrackCandidate
    {
        public:
            /**
             * @brief Construct a new Track Candidate object
             * 
             */
            TrackCandidate();
            /**
             * @brief Destroy the Track Candidate object
             * 
             */
            virtual ~TrackCandidate() = default;

            /**
             * @brief Get the Pid of the track candidate. Output format is standard PDG.
             * 
             * @return long int 
             */
            long int GetPid() const;
            /**
             * @brief Get the Parent Pid of the track candidate.
             * 
             * @return long int 
             */
            long int GetParentPid() const;
            /**
             * @brief Get the 4-Momentum vector of the track.
             * 
             * @return ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > 
             */
            ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > GetMomentum() const;
            /**
             * @brief Get the 4-Position vector of the track.
             * 
             * @return ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > 
             */
            ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > GetPosition() const;

        protected:
            ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > fMom4Vec;
            ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > fPos4Vec;
            long int fPid, fParentPid;
    };

    inline long int TrackCandidate::GetPid() const {return fPid;}
    inline long int TrackCandidate::GetParentPid() const {return fParentPid;}
    inline ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> TrackCandidate::GetMomentum() const {return fMom4Vec;}
    inline ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> TrackCandidate::GetPosition() const {return fPos4Vec;}

#endif