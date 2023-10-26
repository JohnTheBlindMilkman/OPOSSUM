/**
 * @file JJEventCut.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief My class for implementing user-defined event cuts. To be modified.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef JJEventCut_h
    #define JJEventCut_h

    #include <iostream>

    #include "../../EventCandidate.h"
    #include "../EventCut.h"

    class JJEventCut : public EventCut
    {
        public:
            JJEventCut();
            ~JJEventCut();

            bool IsRejected(const EventCandidate &evtCand) const;
    };

#endif