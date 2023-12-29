#include "TrackCandidate.h"

namespace Opossum
{
    TrackCandidate::TrackCandidate()
    {
    }

    std::variant<long int,float> TrackCandidate::GetParticleObservable(const TrackObservable &obs)
    {
        return this->fObservables[obs];
    }
} // namespace Opossum

