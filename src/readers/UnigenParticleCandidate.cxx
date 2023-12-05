#include "UnigenParticleCandidate.h"

namespace Opossum
{
    UnigenParticleCandidate::UnigenParticleCandidate(UParticle *particle)
    {
        this->fObservables[TrackObservable::Px] = static_cast<float>(particle->GetMomentum().Px());
        this->fObservables[TrackObservable::Py] = static_cast<float>(particle->GetMomentum().Py());
        this->fObservables[TrackObservable::Pz] = static_cast<float>(particle->GetMomentum().Pz());
        this->fObservables[TrackObservable::Energy] = static_cast<float>(particle->GetMomentum().E());
        this->fObservables[TrackObservable::TotalMomentum] = static_cast<float>(particle->GetMomentum().Mag());
        this->fObservables[TrackObservable::TransverseMomentum] = static_cast<float>(particle->GetMomentum().Pt());
        this->fObservables[TrackObservable::Beta] = static_cast<float>(particle->GetMomentum().Beta());
        this->fObservables[TrackObservable::Rapidity] = static_cast<float>(particle->GetMomentum().Rapidity());

        this->fObservables[TrackObservable::X] = static_cast<float>(particle->GetPosition().X());
        this->fObservables[TrackObservable::Y] = static_cast<float>(particle->GetPosition().Y());
        this->fObservables[TrackObservable::Z] = static_cast<float>(particle->GetPosition().Z());
        this->fObservables[TrackObservable::Mass] = static_cast<float>(particle->GetPosition().M());
        this->fObservables[TrackObservable::Mass2] = static_cast<float>(particle->GetPosition().M2());

        this->fObservables[TrackObservable::PID] = static_cast<long int>(particle->GetPdg());
        this->fObservables[TrackObservable::ParentPID] = static_cast<long int>(particle->GetParent());
        this->fObservables[TrackObservable::AzimimuthalAngle] = static_cast<float>(particle->GetPosition().Phi());
        this->fObservables[TrackObservable::PolarAngle] = static_cast<float>(particle->GetPosition().Theta());
    }

    UnigenParticleCandidate::~UnigenParticleCandidate()
    {
        
    }
}