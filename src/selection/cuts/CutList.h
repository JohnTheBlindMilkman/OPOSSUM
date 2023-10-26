/**
 * @file CutList.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Depricated class. To be modified or removed.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CutList_h
    #define CutList_h

    namespace CutList
    {
        enum class EventCut
        {
            EIsWithinCentrality
        };

        enum class TrackCut
        {
            EIsWithinRapidity,
            EIsWithinMomentum
        };

        enum class PairCut
        {
            EIsOutsideOpeningAngle
        };

    }; // namespace CutList

#endif