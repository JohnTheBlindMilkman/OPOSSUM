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

    namespace Opossum
    {
        class EventCandidate : public GenericCandidate<EventObservable>
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
                ~EventCandidate() = default;
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
                bool IsGoodEvent() const;
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
                bool SelectTracks(const std::unordered_map<TrackObservable,CutEntry> &trackCut);
                /**
                 * @brief Get the list of accepted tracks
                 * 
                 * @return std::vector<TrackCandidate> 
                 */
                std::vector<TrackCandidate> GetAcceptedTracks() const;
                /**
                 * @brief Get the list of rejected tracks
                 * 
                 * @return std::vector<TrackCandidate> 
                 */
                std::vector<TrackCandidate> GetRejectedTracks() const;

            private:
                bool fIsGoodEvent; // default = true
                std::vector<TrackCandidate> fAllTracks, fGoodTracks, fBadTracks;

        };

        inline void EventCandidate::AddTrack(TrackCandidate cand) {fAllTracks.push_back(cand);}
        inline bool EventCandidate::IsGoodEvent() const {return fIsGoodEvent;}
        inline void EventCandidate::SetGoodEvent(bool good) {fIsGoodEvent = good;}
        inline std::vector<TrackCandidate> EventCandidate::GetAcceptedTracks() const {return fGoodTracks;}
        inline std::vector<TrackCandidate> EventCandidate::GetRejectedTracks() const {return fBadTracks;}
    }

#endif