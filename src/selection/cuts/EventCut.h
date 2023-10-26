/**
 * @file EventCut.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Base class for implementing user-defined event cuts. To be modified.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef EventCut_h
    #define EventCut_h

    #include "../EventCandidate.h"

    class EventCut
    {
        public:
            EventCut();
            virtual ~EventCut() = default;

            bool IsRejected(const EventCandidate &evtCand) const;
    };

#endif