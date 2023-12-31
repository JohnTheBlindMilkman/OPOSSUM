/**
 * @file Analysis.h
 * @author Jedrzej Kolas (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Abstract base class of the Analysis. 
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef Analysis_h
    #define Analysis_h

    #include "Result.h"
    #include "../selection/EventCandidate.h"

    class Analysis
    {
        public:
            /**
             * @brief Construct a new Analysis object
             * 
             */
            Analysis();
            /**
             * @brief Destroy the Analysis object
             * 
             */
            virtual ~Analysis() = default;

            /**
             * @brief Perform analysis on the EventCandidate object. Override this method in your own implementation of the Analysis class.
             * 
             * @param evtCand 
             * @return Result 
             */
            Result PerformAnalysis(const EventCandidate &evtCand);
    };

#endif