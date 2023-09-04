#include "UnigenParticleCandidate.h"

UnigenParticleCandidate::UnigenParticleCandidate(UParticle *particle)
{
    fMom4Vec = ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>(particle->GetMomentum().Px(),particle->GetMomentum().Py(),particle->GetMomentum().Pz(),particle->GetMomentum().E());
    fPos4Vec = ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>(particle->GetPosition().X(),particle->GetPosition().Y(),particle->GetPosition().Z(),particle->GetPosition().M());
    fPid = particle->GetPdg();
    fParentPid = particle->GetParent();
}

UnigenParticleCandidate::~UnigenParticleCandidate()
{
    
}