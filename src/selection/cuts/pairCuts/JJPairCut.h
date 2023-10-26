/**
 * @file JJPairCut.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief My class for implementing user-defined pair cuts. To be modified.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef JJPairCut_h
    #define JJPairCut_h

    #include <iostream>

    #include "../../TrackCandidate.h"
    #include "../PairCut.h"

    class JJPairCut : public PairCut
    {
        public:
            JJPairCut() = default;
            ~JJPairCut() = default;

            bool IsRejected(const TrackCandidate &trackCand1, const TrackCandidate &trackCand2) const;
    };

#endif