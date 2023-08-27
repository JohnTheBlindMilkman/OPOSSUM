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