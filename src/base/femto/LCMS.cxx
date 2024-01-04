#include "LCMS.h"

namespace Opossum
{
    LCMS::LCMS() :
            fName("LCMS"), 
            fXAxisDesc("q_{out} [GeV/c]"), 
            fYAxisDesc("q_{side} [GeV/c]"), 
            fZAxisDesc("q_{long} [GeV/c]"), 
            fSingleAxisDesc("q_{inv} [GeV/c]"), 
            fX(0), 
            fY(0), 
            fZ(0), 
            fT(0), 
            fPx(0), 
            fPy(0), 
            fPz(0), 
            fE(0), 
            fKt(0) {}

    void LCMS::Calculate(const PairCandidate &pair)
    {
        std::pair<TrackCandidate,TrackCandidate> tracks = pair.GetTracks();

        float tPx    = std::get<float>(tracks.first[TrackObservable::Px]) + std::get<float>(tracks.second[TrackObservable::Px]);
        float tPy    = std::get<float>(tracks.first[TrackObservable::Py]) + std::get<float>(tracks.second[TrackObservable::Py]);
        float tPz    = std::get<float>(tracks.first[TrackObservable::Pz]) + std::get<float>(tracks.second[TrackObservable::Pz]);
        float tE     = std::get<float>(tracks.first[TrackObservable::Energy]) + std::get<float>(tracks.second[TrackObservable::Energy]);
        float tPt    = sqrt(tPx * tPx + tPy * tPy);
        float tMt    = sqrt(tE * tE - tPz * tPz);  // mCVK;
        float tBeta  = tPz / tE;
        float tGamma = tE / tMt;

        // Transform to LCMS

        float particle1lcms_pz = tGamma * (std::get<float>(tracks.first[TrackObservable::Pz]) - tBeta * std::get<float>(tracks.first[TrackObservable::Energy]));
        float particle1lcms_e  = tGamma * (std::get<float>(tracks.first[TrackObservable::Energy]) - tBeta * std::get<float>(tracks.first[TrackObservable::Pz]));
        float particle2lcms_pz = tGamma * (std::get<float>(tracks.second[TrackObservable::Pz]) - tBeta * std::get<float>(tracks.second[TrackObservable::Energy]));
        float particle2lcms_e  = tGamma * (std::get<float>(tracks.second[TrackObservable::Energy]) - tBeta * std::get<float>(tracks.second[TrackObservable::Pz]));

        // Rotate in transverse plane

        float particle1lcms_px = (std::get<float>(tracks.first[TrackObservable::Px]) * tPx + std::get<float>(tracks.first[TrackObservable::Py]) * tPy) / tPt;
        float particle1lcms_py = (-std::get<float>(tracks.first[TrackObservable::Px]) * tPy + std::get<float>(tracks.first[TrackObservable::Py]) * tPx) / tPt;

        float particle2lcms_px = (std::get<float>(tracks.second[TrackObservable::Px]) * tPx + std::get<float>(tracks.second[TrackObservable::Py]) * tPy) / tPt;
        float particle2lcms_py = (-std::get<float>(tracks.second[TrackObservable::Px]) * tPy + std::get<float>(tracks.second[TrackObservable::Py]) * tPx) / tPt;

        fPx           = particle1lcms_px - particle2lcms_px;
        fPy           = particle1lcms_py - particle2lcms_py;
        fPz           = particle1lcms_pz - particle2lcms_pz;
        float mDE = particle1lcms_e - particle2lcms_e;
        fE           = sqrt(abs(fX * fX + fY * fY + fZ * fZ - mDE * mDE));
        fKt = 0.5 * tPt;
    }
}