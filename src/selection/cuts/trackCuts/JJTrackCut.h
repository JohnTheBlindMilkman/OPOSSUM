/**
 * @file JJTrackCut.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief My class for implementing user-defined track cuts. To be modified.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef JJTrackCut_h
    #define JJTrackCut_h

    #include <iostream>

    #include "../../TrackCandidate.h"
    #include "../TrackCut.h"

    class JJTrackCut : public TrackCut
    {
        public:
            JJTrackCut();
            ~JJTrackCut();

            bool IsRejected(const TrackCandidate &trackCand) const;
    };

#endif