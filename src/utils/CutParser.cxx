#include "CutParser.h"

namespace Opossum
{
    CutParser::CutParser() : fEventLut({{"cent",EventObservable::Centrality},
                            {"B",EventObservable::ImpactParameter},
                            {"X",EventObservable::X},
                            {"Y",EventObservable::Y},
                            {"Z",EventObservable::Z},
                            {"psi",EventObservable::ReactionPlaneAngle}}),
                            fTrackLut({{"PID",TrackObservable::PID},
                            {"pPID",TrackObservable::ParentPID},
                            {"rap",TrackObservable::Rapidity},
                            {"totP",TrackObservable::TotalMomentum},
                            {"Pt",TrackObservable::TransverseMomentum},
                            {"Px",TrackObservable::Px},
                            {"Py",TrackObservable::Py},
                            {"Pz",TrackObservable::Pz},
                            {"E",TrackObservable::Energy},
                            {"X",TrackObservable::X},
                            {"Y",TrackObservable::Y},
                            {"Z",TrackObservable::Z},
                            {"mass",TrackObservable::Mass},
                            {"mass2",TrackObservable::Mass2},
                            {"theta",TrackObservable::PolarAngle},
                            {"phi",TrackObservable::AzimimuthalAngle},}),
                            fPairLut({{"alpha",PairObservable::OpeningAngle},
                            {"qinv",PairObservable::QInvariant},
                            {"qout",PairObservable::QOut},
                            {"qside",PairObservable::QSide},
                            {"qlong",PairObservable::QLong},
                            {"kT",PairObservable::kT},
                            {"phi",PairObservable::AzimimuthalAngle},
                            {"dt",PairObservable::TimeDifference},})
    {
    }

    CutParser::~CutParser()
    {
    }
}