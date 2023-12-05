#include "UnigenEventCandidate.h"

namespace Opossum
{
    UnigenEventCandidate::UnigenEventCandidate(UEvent *event)
    {
        this->fObservables[EventObservable::ImpactParameter] = static_cast<float>(event->GetB());
        this->fObservables[EventObservable::ReactionPlaneAngle] = static_cast<float>(event->GetPhi());
        for (int iter = 0; iter < event->GetNpa(); iter++)
        {
            AddTrack(UnigenParticleCandidate(event->GetParticle(iter)));
        }
    }

    UnigenEventCandidate::~UnigenEventCandidate()
    {
        
    }
}