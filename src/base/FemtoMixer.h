/**
 * @file FemtoMixer.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief General class for mixing tracks for femtoscopic analysis
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef FemtoMixer_h
    #define FemtoMixer_h

    #include "../selection/TrackCandidate.h"
    #include "../selection/PairCandidate.h"

    namespace Opossum
    {
        class FemtoMixer
        {
            private:
                /* data */
            public:
                FemtoMixer() = default;
                ~FemtoMixer() = default;

                std::vector<PairCandidate> MakePairs(const std::vector<TrackCandidate> &trackVec);
        };
    }

#endif