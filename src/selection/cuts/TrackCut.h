/**
 * @file TrackCut.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Base class for implementing user-defined track cuts. To be modified.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TrackCut_h
    #define TrackCut_h

    #include "../TrackCandidate.h"

    class TrackCut
    {
        public:
            TrackCut();
            virtual ~TrackCut() = default;

            bool IsRejected(const TrackCandidate &trackCand) const;
    };

#endif