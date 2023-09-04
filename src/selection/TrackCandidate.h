#ifndef TrackCandidate_h
    #define TrackCandidate_h

    #include "Math/LorentzVector.h"

    class TrackCandidate
    {
        public:
            TrackCandidate();
            virtual ~TrackCandidate() = default;

            long int GetPid() const;
            long int GetParentPid() const;
            ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > GetMomentum() const;
            ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > GetPosition() const;

        protected:
            ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > fMom4Vec;
            ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > fPos4Vec;
            long int fPid, fParentPid;
    };

    inline long int TrackCandidate::GetPid() const {return fPid;};
    inline long int TrackCandidate::GetParentPid() const {return fParentPid;};
    inline ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> TrackCandidate::GetMomentum() const {return fMom4Vec;};
    inline ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> TrackCandidate::GetPosition() const {return fPos4Vec;};

#endif