#include "LCMS.h"

namespace Opossum
{
    std::tuple<float,float,float,float> LCMS::CalculateMomentum(const PairCandidate &pair)
    {
        return std::make_tuple(std::get<float>(pair[PairObservable::QInvariant]),std::get<float>(pair[PairObservable::QOut]),std::get<float>(pair[PairObservable::QSide]),std::get<float>(pair[PairObservable::QLong]));
    }
}