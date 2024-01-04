#include "EventMixer.h"

namespace Opossum
{
    std::vector<PairCandidate> EventMixer::MakePairs(const std::vector<TrackCandidate> &trackVec)
    {
        const std::size_t vecSize = trackVec.size();
        std::vector<PairCandidate> pairVec;
        pairVec.reserve((vecSize + vecSize*vecSize)/2); // arithmetic sum to reserve maximal possible vector size for given amount of tracks

        for (std::size_t iter1 = 0; iter1 < vecSize; ++iter1)
            for (std::size_t iter2 = iter1+1; iter2 < vecSize; ++iter2)
            {
                pairVec.push_back(PairCandidate(trackVec.at(iter1),trackVec.at(iter2)));
            }

        return pairVec;
    }
}