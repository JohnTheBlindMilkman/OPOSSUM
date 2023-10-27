/**
 * @file EventCandidate.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Base class for storing event object. It defines the event format for the whole program.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef EventCandidate_h
    #define EventCandidate_h

    #include <iostream>

    #include "TrackCandidate.h"
    #include "cuts/TrackCut.h"

    #include "ROOT/RVec.hxx"

    class EventCandidate
    {
        public:
            /**
             * @brief Construct a new Event Candidate object
             * 
             */
            EventCandidate();
            /**
             * @brief Destroy the Event Candidate object
             * 
             */
            virtual ~EventCandidate() = default;
            
            /**
             * @brief Add track candidate to the event.
             * 
             * @param cand 
             */
            void AddTrack(TrackCandidate cand);
            /**
             * @brief Check if event has been accepted by the selection criteria, stored in the selection.json file.
             * 
             * @return true 
             * @return false 
             */
            bool IsGoodEvent();
            /**
             * @brief Set the Good Event flag of this event.
             * 
             * @param good 
             */
            void SetGoodEvent(bool good);
            /**
             * @brief Perform track selection on all tracks, which are assigned to the event. Returns true if any track has passed the selection criteria, and false otherwise.
             * 
             * @param trackCut 
             * @return true 
             * @return false 
             */
            bool SelectTracks(const TrackCut &trackCut);
            /**
             * @brief Get the list of accepted tracks
             * 
             * @return ROOT::VecOps::RVec<TrackCandidate> 
             */
            ROOT::VecOps::RVec<TrackCandidate> GetAcceptedTracks();
            /**
             * @brief Get the list of rejected tracks
             * 
             * @return ROOT::VecOps::RVec<TrackCandidate> 
             */
            ROOT::VecOps::RVec<TrackCandidate> GetRejectedTracks();


        protected:
            std::unordered_map<EventObservable,ObservableType> fObservables;
            bool fIsGoodEvent; // default = true
            float fB; // in fm
            float fReactionPlaneAngle; // in rad

        private:
            ROOT::VecOps::RVec<TrackCandidate> fAllTracks, fGoodTracks, fBadTracks;

    };

    inline void EventCandidate::AddTrack(TrackCandidate cand) {fAllTracks.push_back(cand);}
    inline bool EventCandidate::IsGoodEvent() {return fIsGoodEvent;}
    inline void EventCandidate::SetGoodEvent(bool good) {fIsGoodEvent = good;}
    inline ROOT::VecOps::RVec<TrackCandidate> EventCandidate::GetAcceptedTracks() {return fGoodTracks;}
    inline ROOT::VecOps::RVec<TrackCandidate> EventCandidate::GetRejectedTracks() {return fBadTracks;}

#endif