/**
 * @file FemtoAnalysis.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Base class of femtoscopic analysis.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef FemtoAnalysis_h
    #define FemtoAnalysis_h

    #include "../Analysis.h"
    #include "../GenericResult.h"
    #include "../../selection/EventCandidate.h"

    namespace Opossum
    {
        class FemtoAnalysis : public Analysis
        {
            public:
                /**
                 * @brief Default constructor
                 * 
                 */
                FemtoAnalysis(/* args */);
                /**
                 * @brief Destroy the Femto Analysis object
                 * 
                 */
                ~FemtoAnalysis();

                /**
                 * @brief Perform femtoscopic analysis on the EventCandidate object. Override this method in your own implementation of the FemtoscopicAnalysis class.
                 * 
                 * @param evtCand 
                 * @return Result 
                 */
                GenericResult PerformAnalysis(const EventCandidate &evtCand);

            private:
        };
    }
    
#endif