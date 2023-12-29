/**
 * @file ObservableList.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Depricated class. To be modified or removed.
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ObservableList_h
    #define ObservableList_h

    namespace Opossum
    {
        enum class EventObservable
        {
            Centrality,
            ImpactParameter,
            X,
            Y,
            Z,
            ReactionPlaneAngle
        };

        enum class TrackObservable
        {
            PID,
            ParentPID,
            Rapidity,
            TotalMomentum,
            TransverseMomentum,
            Px,
            Py,
            Pz,
            Energy,
            X,
            Y,
            Z,
            Time,
            Mass,
            Mass2,
            Beta,
            PolarAngle,
            AzimimuthalAngle
        };

        enum class PairObservable
        {
            OpeningAngle,
            QInvariant,
            QOut,
            QSide,
            QLong,
            kT,
            AzimimuthalAngle,
            TimeDifference
        };

        enum class Relation
        {
            Less,
            More,
            Equal
        };
    }

#endif