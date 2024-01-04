#include "PairCandidate.h"

namespace Opossum
{
    PairCandidate::PairCandidate(const TrackCandidate &particle1, const TrackCandidate &particle2) : fTrack1(particle1), fTrack2(particle2)
    {
        this->fObservables[PairObservable::AzimimuthalAngle] = (std::get<float>(fTrack1.GetParticleObservable(TrackObservable::AzimimuthalAngle)) + std::get<float>(fTrack2.GetParticleObservable(TrackObservable::AzimimuthalAngle))) / 2;
        this->fObservables[PairObservable::kT] = (std::get<float>(fTrack1.GetParticleObservable(TrackObservable::TransverseMomentum)) + std::get<float>(fTrack2.GetParticleObservable(TrackObservable::TransverseMomentum))) / 2;
        this->fObservables[PairObservable::OpeningAngle] = CalculateOpeningAngle(fTrack1,fTrack2);
    }

    float PairCandidate::CalculateOpeningAngle(TrackCandidate &particle1, TrackCandidate &particle2) const
    {
        float ptot = sqrt(std::get<float>(particle1.GetParticleObservable(TrackObservable::TotalMomentum)) + std::get<float>(particle2.GetParticleObservable(TrackObservable::TotalMomentum)));
        if (ptot <= 0.)
        {
            return 0;
        }
        else
        {
            float arg = (std::get<float>(particle1.GetParticleObservable(TrackObservable::Px))*std::get<float>(particle2.GetParticleObservable(TrackObservable::Px)) +
                        std::get<float>(particle1.GetParticleObservable(TrackObservable::Py))*std::get<float>(particle2.GetParticleObservable(TrackObservable::Py)) +
                        std::get<float>(particle1.GetParticleObservable(TrackObservable::Pz))*std::get<float>(particle2.GetParticleObservable(TrackObservable::Pz))
                        ) / ptot;
            if (arg > 1.)
                return 1.;
            if (arg < -1.)
                return -1.;

            return acos(arg);
        }
    }
}