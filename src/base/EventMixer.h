#ifndef EventMixer_h
    #define EventMixer_h

    #include "../selection/TrackCandidate.h"
    #include "../selection/PairCandidate.h"

    namespace Opossum
    {
        class EventMixer
        {
            private:
                /* data */
            public:
                EventMixer(/* args */) = default;
                ~EventMixer() = default;

                std::vector<PairCandidate> MakePairs(const std::vector<TrackCandidate> &trackVec);
        };

    } // namespace Opossum

#endif