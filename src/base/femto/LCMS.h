/**
 * @file LCMS.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Reference frame class of Longitudinally Co-Moving System (LCMS)
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LCMS_h
    #define LCMS_h

    #include <tuple>
    #include "../../selection/PairCandidate.h"

    namespace Opossum
    {
        class LCMS
        {
            private:
                /* data */
            public:
                LCMS(/* args */) = default;
                ~LCMS() = default;
                /**
                 * @brief Returns decomposed momentum in the LCMS reference frame
                 * 
                 * @param pair PairCandidate object
                 * @return std::tuple<float,float,float,float> 
                 */
                std::tuple<float,float,float,float> CalculateMomentum(const PairCandidate &pair);
        };
    } // namespace Opossum

#endif