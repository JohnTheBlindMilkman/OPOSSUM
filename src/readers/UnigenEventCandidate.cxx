#include "UnigenEventCandidate.h"

UnigenEventCandidate::UnigenEventCandidate(UEvent *event)
{
    this->fB = event->GetB();
    this->fReactionPlaneAngle = event->GetPhi();
    for (int iter = 0; iter < event->GetNpa(); iter++)
    {
        AddTrack(UnigenParticleCandidate(event->GetParticle(iter)));
    }
}

UnigenEventCandidate::~UnigenEventCandidate()
{
    
}