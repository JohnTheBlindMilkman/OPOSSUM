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

    #include "GenericCandidate.h"

    namespace Opossum
    {
        class TrackCandidate : public GenericCandidate<TrackObservable>
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
        };
    }

#endif