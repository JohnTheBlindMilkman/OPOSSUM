#include "CF1D.h"

namespace Opossum
{
    template<typename T>
    CF1D<T>::CF1D() : CF<T>::fCorrectionFunction([](const PairCandidate &pair){return pair;}), fCFHistogram("CF1D","",300,0,3.0)
    {}
    template<typename T>
    CF1D<T>::~CF1D()
    {}
    template<typename T>
    void CF1D<T>::ApplyCorrection(std::function<PairCandidate(const PairCandidate&)> &&correctionFunction)
    {
        CF<T>::fCorrectionFunction = std::move(correctionFunction);
    }
    template<typename T>
    void CF1D<T>::AddPair(const PairCandidate &pair, const double &weight)
    {
        fCFHistogram.Fill(std::get<0>(CF<T>::fFrameOfReference.CalculateMomentum(CF<T>::fCorrectionFunction(pair))),weight); // maybe move would be better for this operation?
    }

} // namespace Opossum
