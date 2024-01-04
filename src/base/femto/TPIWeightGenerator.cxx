#include "TPIWeightGenerator.h"
#include "Math/Math.h"

namespace Opossum
{
    TPIWeightGenerator::TPIWeightGenerator() :
    fPairType(FemtoConstants::PairType::Unknown),
    fD0s(0.,0.), 
    fF0s(0.,0.), 
    fD0t(0.,0.), 
    fF0t(0.,0.),
    fPionac(0),
    fOneoveracsq(0),
    fTwopioverac(0),
    fCoulqscpart(0),
    fEuler(0),
    fF0(0),
    fD0(0),
    fTwospin(0),
    fWritegrps(0),
    fPcount(0),
    fCoulombSteps(170),
    fRStarOutS(0),
    fRStarSideS(0),
    fRStarLongS(0),
    fRStarS(0),
    fRStarOut(0),
    fRStarSide(0),
    fRStarLong(0),
    fRStar(0),
    fKStarOut(0),
    fKStarSide(0),
    fKStarLong(0),
    fKStar(0) {}

    void TPIWeightGenerator::InitializeGamow() 
    {
        using namespace std::complex_literals;

        fTwospin = 0;

        fEuler = 0.577215665;
        fF0    = 7.77 / FemtoConstants::gevToFm;
        fD0    = 2.77 / FemtoConstants::gevToFm;

        fD0s = 0.0 + 0.0i;
        fD0t = 0.0 + 0.0i;

        fF0s = 0.0 + 0.0i;
        fF0t = 0.0 + 0.0i;

        static unsigned short int isospin = 0;
        switch (fPairType)  // some enum values are not handled... - JJ
        {
            case FemtoConstants::PairType::PionPlusPionPlus: 
                fPionac = 387.5 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::KaonPlusKaonPlus:
                fPionac = 109.55 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::PionPlusKaonPlus:
                fPionac    = 248.519 / FemtoConstants::gevToFm;
                fWritegrps = 0;
                break;

            case FemtoConstants::PairType::PionPlusKaonMinus:
                fPionac    = -248.519 / FemtoConstants::gevToFm;
                fWritegrps = 0;
                break;

            case FemtoConstants::PairType::PionPlusProton:
                fPionac    = 222.564 / FemtoConstants::gevToFm;
                fWritegrps = 0;
                break;

            case FemtoConstants::PairType::PionPlusAntiproton:
                fPionac    = -222.564 / FemtoConstants::gevToFm;
                fWritegrps = 0;
                break;

            case FemtoConstants::PairType::ProtonSigmaPlus:
                fPionac  = 51.5553 / FemtoConstants::gevToFm;
                fTwospin = 1;
                // Rijken, Nagels, Yamamoto ESC08 model PTPS No. 185, 2010
                fF0s = 3.85 / FemtoConstants::gevToFm;
                fD0s = 3.40 / FemtoConstants::gevToFm;
                fF0t = -0.62 / FemtoConstants::gevToFm;
                fD0t = -2.13 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::ProtonAntiSigmaPlus:
                fPionac = -51.5553 / FemtoConstants::gevToFm;

                // from antiproton - lambda
                fF0s = {-1.20 / FemtoConstants::gevToFm, 0.37 / FemtoConstants::gevToFm};
                fF0t = {-1.20 / FemtoConstants::gevToFm, 0.37 / FemtoConstants::gevToFm};
                break;

            case FemtoConstants::PairType::ProtonLambda:
                // ESC08
                fF0s = 2.70 / FemtoConstants::gevToFm;
                fD0s = 2.97 / FemtoConstants::gevToFm;
                fF0t = 1.65 / FemtoConstants::gevToFm;
                fD0t = 3.63 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::ProtonAntiLambda:
                fPionac = 0.0;

                fF0s = {-1.20 / FemtoConstants::gevToFm, 0.37 / FemtoConstants::gevToFm};
                fF0t = {-1.20 / FemtoConstants::gevToFm, 0.37 / FemtoConstants::gevToFm};
                break;

            case FemtoConstants::PairType::SigmaPlusSigmaPlus:
                fPionac  = 45.4709 / FemtoConstants::gevToFm;
                fTwospin = 1;
                break;

            case FemtoConstants::PairType::SigmaPlusAntiSigmaPlus:
                fPionac = -45.4709 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::ProtonProton:
                fPionac  = 57.63975274 / FemtoConstants::gevToFm;
                fTwospin = 1;

                //    d0s.real() = 2.77 / FemtoConstants::gevToFm;
                //    f0s.real() = 7.77 / FemtoConstants::gevToFm;
                fD0t = 1.7 / FemtoConstants::gevToFm;
                fF0t = -5.4 / FemtoConstants::gevToFm;

                // ESC08
                fF0s = 7.771 / FemtoConstants::gevToFm;
                fD0s = 2.754 / FemtoConstants::gevToFm;
                //    f0t.real() = ? / FemtoConstants::gevToFm; no data from ESC08
                //    d0t.real() = ? / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::KaonPlusProton:
                fPionac = 83.59432006 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::KaonPlusAntiproton:
                fPionac = -83.59432006 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::PionPlusPionMinus:
                fPionac = -387.5 / FemtoConstants::gevToFm;
                break;

                /*   case FemtoConstants::PairType::kPionPlusPionPlus: {//16 ?? same
            pionac = -387.5 / FemtoConstants::gevToFm;
                } break;*/
            case FemtoConstants::PairType::LambdaLambda:
                fPionac = 0;

                // ESC08
                fF0s = 0.88 / FemtoConstants::gevToFm;
                fD0s = 4.34 / FemtoConstants::gevToFm;
                fF0t = 0.88 / FemtoConstants::gevToFm;
                fD0t = 4.34 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::ProtonXiZero:
                fPionac = 0;

                // ESC08
                if (isospin == 0) 
                {
                    fF0s = 0.0;
                    fD0s = 0.0;
                    fF0t = -6.90 / FemtoConstants::gevToFm;
                    fD0t = 1.18 / FemtoConstants::gevToFm;
                    isospin = 1;
                } 
                else if (isospin == 1) 
                {
                    fF0s = -0.58 / FemtoConstants::gevToFm;
                    fD0s = -2.71 / FemtoConstants::gevToFm;
                    fF0t = -3.49 / FemtoConstants::gevToFm;
                    fD0t = 0.60 / FemtoConstants::gevToFm;
                    isospin = 0;
                }
                break;

            case FemtoConstants::PairType::NeutronXiMinus:
                fPionac = 0;

                // ESC08
                if (isospin == 0) 
                {
                    fF0s = 0.0;
                    fD0s = 0.0;
                    fF0t = -6.90 / FemtoConstants::gevToFm;
                    fD0t = 1.18 / FemtoConstants::gevToFm;
                    isospin = 1;
                } 
                else if (isospin == 1) 
                {
                    fF0s = -0.58 / FemtoConstants::gevToFm;
                    fD0s = -2.71 / FemtoConstants::gevToFm;
                    fF0t = -3.49 / FemtoConstants::gevToFm;
                    fD0t = 0.60 / FemtoConstants::gevToFm;
                    isospin = 0;
                }
                break;

            case FemtoConstants::PairType::ProtonXiMinus:
                fPionac = 49.2788901 / FemtoConstants::gevToFm;

                // ESC08
                if (isospin == 0) 
                {
                    fF0s = 0.0;
                    fD0s = 0.0;
                    fF0t = -6.90 / FemtoConstants::gevToFm;
                    fD0t = 1.18 / FemtoConstants::gevToFm;
                    isospin = 1;
                } 
                else if (isospin == 1) 
                {
                    fF0s = -0.58 / FemtoConstants::gevToFm;
                    fD0s = -2.71 / FemtoConstants::gevToFm;
                    fF0t = -3.49 / FemtoConstants::gevToFm;
                    fD0t = 0.60 / FemtoConstants::gevToFm;
                    isospin = 0;
                }
                break;

            case FemtoConstants::PairType::NeutronXiZero:
                fPionac = 0;

                // ESC08
                if (isospin == 0) 
                {
                    fF0s = 0.0;
                    fD0s = 0.0;
                    fF0t = -6.90 / FemtoConstants::gevToFm;
                    fD0t = 1.18 / FemtoConstants::gevToFm;
                    isospin = 1;
                } 
                else if (isospin == 1) 
                {
                    fF0s = -0.58 / FemtoConstants::gevToFm;
                    fD0s = -2.71 / FemtoConstants::gevToFm;
                    fF0t = -3.49 / FemtoConstants::gevToFm;
                    fD0t = 0.60 / FemtoConstants::gevToFm;
                    isospin = 0;
                }
                break;

            case FemtoConstants::PairType::NeutronProton:
                fPionac = 0;

                // ESC08
                fF0s = 23.735 / FemtoConstants::gevToFm;
                fD0s = 2.694 / FemtoConstants::gevToFm;
                fF0t = -5.428 / FemtoConstants::gevToFm;
                fD0t = 1.753 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::NeutronNeutron:
                fPionac = 0;

                // ESC08
                fF0s = 16.51 / FemtoConstants::gevToFm;
                fD0s = 2.85 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::ProtonSigmaZero:
                fPionac = 0.0;

                // ESC08
                fF0s = 2.70 / FemtoConstants::gevToFm;
                fD0s = 2.97 / FemtoConstants::gevToFm;
                fF0t = 1.65 / FemtoConstants::gevToFm;
                fD0t = 3.63 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::SigmaZeroSigmaZero:
                fPionac = 0;

                // ESC08
                fF0s = 0.88 / FemtoConstants::gevToFm;
                fD0s = 4.34 / FemtoConstants::gevToFm;
                fF0t = 0.88 / FemtoConstants::gevToFm;
                fD0t = 4.34 / FemtoConstants::gevToFm;
                break;

            case FemtoConstants::PairType::LambdaSigmaZero:
                fPionac = 0;
                // ESC08
                fF0s = 0.88 / FemtoConstants::gevToFm;
                fD0s = 4.34 / FemtoConstants::gevToFm;
                fF0t = 0.88 / FemtoConstants::gevToFm;
                fD0t = 4.34 / FemtoConstants::gevToFm;
                break;
        }

        fOneoveracsq = 1.0 / (fPionac * fPionac);
        fTwopioverac = 2.0 * ROOT::Math::Pi() / fPionac;
        double tpaoverk; // this is never used - JJ

        for (int iter = 0; iter < 2000; iter++) //is this a integral? - JJ
        {
            tpaoverk = fTwopioverac / (iter * 0.0002 + 0.0001); // what are those numbers? - JJ
            //  gamov[iter] = tpaoverk * 1.0 / (exp(tpaoverk) - 1);
        }
    }

    void TPIWeightGenerator::PairKinematics(const PairCandidate &pair) 
    {
        std::pair<TrackCandidate,TrackCandidate> tracks = pair.GetTracks();
        double tPx = std::get<float>(tracks.first[TrackObservable::Px]) + std::get<float>(tracks.second[TrackObservable::Px]);
        double tPy = std::get<float>(tracks.first[TrackObservable::Py]) + std::get<float>(tracks.second[TrackObservable::Py]);
        double tPz = std::get<float>(tracks.first[TrackObservable::Pz]) + std::get<float>(tracks.second[TrackObservable::Pz]);
        double tE1 = std::get<float>(tracks.first[TrackObservable::Energy]);
        double tE2 = std::get<float>(tracks.second[TrackObservable::Energy]);
        double tE  = tE1 + tE2;
        double tPt = tPx * tPx + tPy * tPy;
        double tMt = tE * tE - tPz * tPz;  // mCVK;
        double tM  = sqrt(tMt - tPt);
        tMt          = sqrt(tMt);
        tPt          = sqrt(tPt);
        // double tBetat = tPt/tMt;

        // Boost to LCMS
        double tBeta  = tPz / tE;
        double tGamma = tE / tMt;
        fKStarLong      = tGamma * (std::get<float>(tracks.first[TrackObservable::Pz]) - tBeta * tE1);
        double tE1L   = tGamma * (tE1 - tBeta * std::get<float>(tracks.first[TrackObservable::Pz]));

        fKStarOut  = (std::get<float>(tracks.first[TrackObservable::Px]) * tPx + std::get<float>(tracks.second[TrackObservable::Py]) * tPy) / tPt;
        fKStarSide = (-std::get<float>(tracks.first[TrackObservable::Px]) * tPy + std::get<float>(tracks.second[TrackObservable::Py]) * tPx) / tPt;

        fKStarOut = tMt / tM * (fKStarOut - tPt / tMt * tE1L);


        double tDX    = std::get<float>(tracks.first[TrackObservable::X]) - std::get<float>(tracks.second[TrackObservable::X]);
        double tDY    = std::get<float>(tracks.first[TrackObservable::Y]) - std::get<float>(tracks.second[TrackObservable::Y]);
        double tRLong = std::get<float>(tracks.first[TrackObservable::Z]) - std::get<float>(tracks.second[TrackObservable::Z]);
        double tDTime = std::get<float>(tracks.first[TrackObservable::Time]) - std::get<float>(tracks.second[TrackObservable::Time]);

        double tROut  = (tDX * tPx + tDY * tPy) / tPt;
        double tRSide = (-tDX * tPy + tDY * tPx) / tPt;

        fRStarSide  = tRSide;
        fRStarSideS = fRStarSide / FemtoConstants::gevToFm;

        fRStarLong              = tGamma * (tRLong - tBeta * tDTime);
        double tDTimePairLCMS = tGamma * (tDTime - tBeta * tRLong);

        fRStarLongS = fRStarLong / FemtoConstants::gevToFm;
        // 1/.1973
        tBeta      = tPt / tMt;
        tGamma     = tMt / tM;
        fRStarOut  = tGamma * (tROut - tBeta * tDTimePairLCMS);
        fRStarOutS = fRStarOut / FemtoConstants::gevToFm;
        //   double tDTimePairCMS = tGamma*(tDTimePairLCMS - tBeta* tROut);
        fRStar = ::sqrt(fRStarOut * fRStarOut + fRStarSide * fRStarSide + fRStarLong * fRStarLong);
        fKStar = ::sqrt(fKStarOut * fKStarOut + fKStarSide * fKStarSide + fKStarLong * fKStarLong);
        if (fKStarOut < 0) fKStar = -fKStar;
        fRStarS = fRStar / FemtoConstants::gevToFm;
    }

    double TPIWeightGenerator::CalculateWeight(const PairCandidate &pair) 
    {
        double tWeight = 0;
        std::pair<TrackCandidate,TrackCandidate> tracks = pair.GetTracks();
        std::pair<long int,long int> tPidPair(std::get<long int>(tracks.first[TrackObservable::PID]),std::get<long int>(tracks.second[TrackObservable::PID]));
        auto pairIterator = FemtoConstants::pairMap.find(tPidPair);
        fPairType = (pairIterator == FemtoConstants::pairMap.end()) ? FemtoConstants::PairType::Unknown : (*pairIterator).second;

        if (PairIsSuported(pair))
        {
            std::pair<TrackCandidate,TrackCandidate> tracks = pair.GetTracks();
            std::pair<long int,long int> tPidPair(std::get<long int>(tracks.first[TrackObservable::PID]),std::get<long int>(tracks.second[TrackObservable::PID]));
            fPairType = FemtoConstants::pairMap.at(tPidPair);

            InitializeGamow();
            PairKinematics(pair);

            if (tPidPair.first != tPidPair.second) // if not identical 
            {
                if (fabs(fPionac) > 0.1) 
                {

                    if (fabs(fD0s.real()) > 0.00001)
                        tWeight = GetCoulombStrong();
                    else
                        tWeight = GetCoulomb();
                } 
                else 
                {
                    tWeight = GetStrong();
                    if (std::isnan(tWeight) == 1) 
                        return 1;
                }
            } 
            else 
            {
                if (fPairType == FemtoConstants::PairType::PionZeroPionZero) 
                { 
                    return GetQuantum(); 
                }
                if (fabs(fPionac) > 0.1) 
                {
                    if (fPairType != FemtoConstants::PairType::ProtonProton)
                        tWeight = GetQuantumCoulomb();
                    else
                        tWeight = GetQuantumCoulombStrong();
                } 
                else 
                {
                    tWeight = GetQuantumStrong();
                }
            }
        }

        return tWeight;
    }

    bool TPIWeightGenerator::PairIsSuported(const PairCandidate &pair) const
    {
        std::pair<TrackCandidate,TrackCandidate> tracks = pair.GetTracks();
        std::pair<long int,long int> tPidPair(std::get<long int>(tracks.first[TrackObservable::PID]),std::get<long int>(tracks.second[TrackObservable::PID]));
        auto pairIterator = FemtoConstants::pairMap.find(tPidPair);
        return (pairIterator == FemtoConstants::pairMap.end()) ? false : true;
    }

    double TPIWeightGenerator::Gamow(double arg) const 
    {
        //   if (arg<0.0001)
        //     return 0.0;
        //   if (arg > 0.4)
        long double eta = fTwopioverac / arg;
        return (eta) *1.0 / (exp(eta) - 1.0);
        //   int bin = arg / 0.0002;
        //   double b1 = bin*0.0002 + 0.0001;
        //   double b2 = bin*0.0002 + 0.0003;
        //   return ((gamov[bin+1] * (arg - b1) + gamov[bin] * (b2 - arg)) / 0.0002);
    }

    double TPIWeightGenerator::GetQuantumCoulombStrong() 
    {
        using namespace std::complex_literals;

        if (fRStarS < 0.0000000001)
            return 1.0;

        if (fRStarS < 1.0 / FemtoConstants::gevToFm) 
            return GetQuantumCoulomb();

        double tKstRst    = fKStarOut * fRStarOutS + fKStarSide * fRStarSideS + fKStarLong * fRStarLongS;
        long double kstar = fabs(fKStar);
        long double rho   = fRStarS * kstar;

        int ccase         = 0;
        static int pcount = 0; // is not used - JJ
        int wavesign      = 1;

        // Classical limit - if distance is larger than Coulomb radius,
        // the interaction does not matter
        //  if (fabs(fRStarS) > fabs(pionac)) return (1.0 + wavesign*cos(2*tKstRst));

        // Classical limit - in the case of large k* we go to
        // classical coulomb interaction
        long double testp = rho * (1.0 + tKstRst / (rho));
        long double testm = rho * (1.0 - tKstRst / (rho));

        std::complex<long double> ffplus, ffminus;
        if ((testp > 15.0) && (testm > 15.0)) 
        {
            double asym;
            asym = (1.0 - 1.0 / (fRStarS * (1.0 - tKstRst / rho) * fPionac * kstar * kstar)) / Gamow(kstar);
            //      std::cout << "as1 " << asym << std::endl;
            asym = sqrt(asym);
            if (asym < 1.0)
                ffminus.real(1.0 + (asym - 1.0) * 2.0);
            else
                ffminus.real(1.0 + (asym - 1.0) / 2.0);

            ffminus.imag(sqrt(asym * asym - ffminus.real() * ffminus.real()));

            asym = (1.0 - 1.0 / (fRStarS * (1.0 + tKstRst / rho) * fPionac * kstar * kstar)) / Gamow(kstar);
            //      std::cout << "as2 " << asym << std::endl;
            asym = sqrt(asym);
            if (asym < 1.0)
                ffplus.real(1.0 + (asym - 1.0) * 2.0);
            else
                ffplus.real(1.0 + (asym - 1.0) / 2.0);

            ffplus.imag(sqrt(asym * asym - ffplus.real() * ffplus.real()));
        }
        // Check for the classical limit in both functions separately
        else if (((testp < 15.0) && (testm < 15.0)))  // ||
        {
            // Calculate the F function
            GetFFdouble(ffplus, ffminus);
            ccase = 1;
        } 
        else if (testp < 15.0) 
        {
            double asym;
            GetFFsingle(ffplus, 1);
            GetFFsingle(ffminus, -1);
            if ((fabs(ffminus.real()) > 2.0) || fabs(ffminus.imag()) > 2.0) 
            {
                asym = (1.0 - 1.0 / (fRStarS * (1.0 - tKstRst / (rho) *fPionac * kstar * kstar))) / Gamow(kstar);
                asym = sqrt(asym);
                if (asym < 1.0)
                    ffminus.real(1.0 + (asym - 1.0) * 2.0);
                else
                    ffminus.real(1.0 + (asym - 1.0) / 2.0);

                ffminus.imag(sqrt(asym * asym - ffminus.real() * ffminus.real()));
            }
            ccase = 2;
        }
        else 
        {
            double asym;
            GetFFsingle(ffminus, -1);
            GetFFsingle(ffplus, 1);
            if ((fabs(ffplus.real()) > 2.0) || fabs(ffplus.imag()) > 2.0) 
            {
                asym = (1.0 - 1.0 / (fRStarS * (1.0 + tKstRst / (rho) *fPionac * kstar * kstar))) / Gamow(kstar);
                asym = sqrt(asym);
                if (asym < 1.0)
                    ffplus.real(1.0 + (asym - 1.0) * 2.0);
                else
                    ffplus.real(1.0 + (asym - 1.0) / 2.0);

                ffplus.imag(sqrt(asym * asym - ffplus.real() * ffplus.real()));
            }
            ccase = 3;
        }

        long double eta = 1.0 / (kstar * fPionac);
        long double hfun = GetH(eta);
        std::complex<long double> gtilde = GetG(eta, rho, hfun);
        std::complex<long double> gtilor = gtilde / static_cast<long double>(fRStarS);

        std::complex<long double> fcouls, fcoult;
        Getfc(kstar, eta, hfun, fcouls, fcoult);

        std::complex<long double> fgs = gtilor * fcouls;
        long double fgmods = norm(fgs);

        std::complex<long double> fgt = gtilor * fcoult;
        long double fgmodt = norm(fgt);

        std::complex<long double> expikr(cos(tKstRst),-sin(tKstRst));

        std::complex<long double> expikrc  = conj(expikr);
        std::complex<long double> ffplusc  = conj(ffplus);
        std::complex<long double> ffminusc = conj(ffminus);

        std::complex<long double> expikr2  = pow(expikr, 2);
        std::complex<long double> expikrc2 = conj(expikr2);
        std::complex<long double> sterm    = expikr2 * ffplus * ffminusc;
        std::complex<long double> tterm    = expikrc2 * ffminus * ffplusc;

        std::complex<long double> epfpc = expikr * ffplus;
        std::complex<long double> emfmc = expikrc * ffminus;

        long double fcgefhs = (fgs.real() * emfmc.real() + fgs.imag() * emfmc.imag());
        long double fcgefgs = (fgs.real() * epfpc.real() + fgs.imag() * epfpc.imag());

        long double fcgefht = (fgt.real() * emfmc.real() + fgt.imag() * emfmc.imag());
        long double fcgefgt = (fgt.real() * epfpc.real() + fgt.imag() * epfpc.imag());

        long double smult = 1 + wavesign;

        if (!finite(ffminus.real())) 
            std::cout << "FFMinus Re not a number ! " << testp << " " << testm << " " << ccase << std::endl;

        if (!finite(ffminus.imag())) 
            std::cout << "FFMinus Im not a number !" << testp << " " << testm << " " << ccase << std::endl;

        if ((ffplus.real() > 2.0) || (ffplus.real() < -2.0))
            std::cout << std::endl << "FFplus Re wild !" << ffplus.real() << " case " << ccase << " " << testp << " " << testm << std::endl;

        if ((ffplus.imag() > 2.0) || (ffplus.imag() < -2.0))
            std::cout << "FFplus Im wild !" << ffplus.imag() << " case " << ccase << " " << testp << " " << testm << std::endl;

        if ((ffminus.real() > 2.0) || (ffminus.real() < -2.0))
            std::cout << std::endl << "FFminus Re wild !" << ffminus.real() << " case " << ccase << std::endl;

        if ((ffminus.imag() > 2.0) || (ffminus.imag() < -2.0))
            std::cout << "FFminus Im wild !" << ffminus.imag() << " case " << ccase << std::endl;

        //  coulqscpart = 0.5 * Gamow(kstar) * (modl2(ffplus) + modl2(ffminus));

        //   return (0.5 * Gamow(kstar) *
        //      (modl2(ffplus) + wavesign*sterm.real() + wavesign*tterm.real() + modl2(ffminus)));
        if (fTwospin == 1) 
        {
            wavesign            = 1;
            smult               = 2;
            long double singlet = (0.5 * Gamow(kstar) * (2.0 * fgmods * smult + norm(ffplus) + norm(ffminus) + wavesign * sterm.real() + wavesign * tterm.real() + smult * 2 * (fcgefhs + fcgefgs)));
            
            wavesign            = -1;
            smult               = 0;
            long double triplet = (0.5 * Gamow(kstar) * (2.0 * fgmodt * smult + norm(ffplus) + norm(ffminus) + wavesign * sterm.real() + wavesign * tterm.real() + smult * 2 * (fcgefht + fcgefgt)));
            //    scmp = singlet;
            //    tcmp = triplet;

            //    ccmp = 0.5 * Gamow(kstar) * (modl2(ffplus) + modl2(ffminus));
            //    gcmp = fgmod;

            return (0.25 * singlet + 0.75 * triplet);
            //    return triplet;
        } 
        else
        {
            return (0.5 * Gamow(kstar) * (2.0 * fgmods * smult + norm(ffplus) + norm(ffminus) + wavesign * sterm.real() + wavesign * tterm.real() + smult * 2 * (fcgefhs + fcgefgs)));
        }
        
    }

    double TPIWeightGenerator::GetCoulombStrong() 
    {
        if (fRStarS < 0.0000000001) 
            return 1.0;

        if (fRStarS < 1.0 / FemtoConstants::gevToFm) 
            return GetCoulomb();

        double tKstRst    = fKStarOut * fRStarOutS + fKStarSide * fRStarSideS + fKStarLong * fRStarLongS;
        long double kstar = fabs(fKStar);
        long double rho   = fRStarS * kstar;

        // Classical limit - in the case of large k* we go to
        // classical coulomb interaction
        long double testp = rho * (1.0 + tKstRst / (rho));

        std::complex<long double> ffplus;
        if (testp > 15.0) 
        {
            double asym;
            asym = (1.0 - 1.0 / (fRStarS * (1.0 + tKstRst / rho) * fPionac * kstar * kstar)) / Gamow(kstar);
            asym = sqrt(asym);
            if (asym < 1.0)
                ffplus.real(1.0 + (asym - 1.0) * 2.0);
            else
                ffplus.real(1.0 + (asym - 1.0) / 2.0);

            ffplus.imag(sqrt(asym * asym - ffplus.real() * ffplus.real()));
        } 
        else
        {
            GetFFsingle(ffplus, 1);
        }
        
        long double eta  = 1.0 / (kstar * fPionac);
        long double hfun = GetH(eta);
        std::complex<long double> gtilde  = GetG(eta, rho, hfun);
        std::complex<long double> gtilor  = gtilde/ static_cast<long double>(fRStarS);

        std::complex<long double> fcouls, fcoult;
        Getfc(kstar, eta, hfun, fcouls, fcoult);

        std::complex<long double> fgs = gtilor * fcouls;
        //  long double fgmods = modl2(fgs);

        std::complex<long double> fgt = gtilor * fcoult;
        //  long double fgmodt = modl2(fgt);

        std::complex<long double> expikr(cos(tKstRst),-sin(tKstRst));

        //  dcomplex expikrc = conj(expikr);
        //  dcomplex ffplusc = conj(ffplus);

        //  dcomplex expikr2 = mult(expikr, expikr);
        //  dcomplex expikrc2 = conj(expikr2);

        std::complex<long double> epfpc = expikr * ffplus;
        //  dcomplex emfmc = mult(expikrc, ffminus);

        //   long double fcgefhs = (fgs.real()*emfmc.real() + fgs.imag()*emfmc.imag());
        //  long double fcgefgs = (fgs.real()*epfpc.real() + fgs.imag()*epfpc.imag());
        //  long double fcgefgt = (fgt.real()*epfpc.real() + fgt.imag()*epfpc.imag());
        //  long double fcgefht = (fgt.real()*emfmc.real() + fgt.imag()*emfmc.imag());

        std::complex<long double> fvfs = epfpc + fgs;

        std::complex<long double> fvft = epfpc + fgt;

        //   long double smult = 1+wavesign;

        //  return 0.5 * Gamow(kstar);
        //   return (0.5 * Gamow(kstar) *
        //      (2.0 * fgmods * smult + modl2(ffplus) + modl2(ffminus) +
        //       wavesign*sterm.real() + wavesign*tterm.real() +
        //       smult * 2 * (fcgefhs + fcgefgs)));

        if (fTwospin == 1) 
        {
            //   wavesign = 1;
            //     smult = 2;
            //     long double singlet = (0.5 * Gamow(kstar) *
            //             (2.0 * fgmods * smult + modl2(ffplus) + modl2(ffminus) +
            //              wavesign*sterm.real() + wavesign*tterm.real() +
            //              smult * 2 * (fcgefhs + fcgefgs)));
            //     wavesign = -1;
            //     smult = 0;
            //     long double triplet = (0.5 * Gamow(kstar) *
            //             (2.0 * fgmodt * smult + modl2(ffplus) + modl2(ffminus) +
            //              wavesign*sterm.real() + wavesign*tterm.real() +
            //              smult * 2 * (fcgefht + fcgefgt)));
            //    scmp = singlet;
            //    tcmp = triplet;

            //    ccmp = 0.5 * Gamow(kstar) * (modl2(ffplus) + modl2(ffminus));
            //    gcmp = fgmod;

            long double singlet = Gamow(kstar) * norm(fvfs);
            long double triplet = Gamow(kstar) * norm(fvft);

            //    std::cout << " s t " << singlet << "  " << triplet << "   -   "  << (0.25*singlet+0.75*triplet) << std::endl;

            return (0.25 * singlet + 0.75 * triplet);
            //    return triplet;
        } 
        else
        {
            return Gamow(kstar) * norm(fvfs);
            //     return (0.5 * Gamow(kstar) *
            //        (2.0 * fgmods * smult + modl2(ffplus) + modl2(ffminus) +
            //         wavesign*sterm.real() + wavesign*tterm.real() +
            //                smult * 2 * (fcgefhs + fcgefgs)));
        }
        
    }

    double TPIWeightGenerator::GetStrong() 
    {
        double fr, fi;
        double dr;
        double ar, ai;
        double ir, ii;

        double sr, si;
        double tr, ti;

        double skr, ckr;
        double srk, crk;

        double d0_sr = fD0s.real();
        double d0_si = fD0s.imag(); // is never used - JJ
        double d0_tr = fD0t.real();
        double d0_ti = fD0t.imag(); // is never used - JJ

        double f0_sr = fF0s.real();
        double f0_si = fF0s.imag();
        double f0_tr = fF0t.real();
        double f0_ti = fF0t.imag();

        double kstar  = fabs(fKStar);
        double rstar  = fRStarS;
        double kstrst = fKStarOut * fRStarOutS + fKStarSide * fRStarSideS + fKStarLong * fRStarLongS;
        /*
        if (pairtype == 8) {
        f0_sr = 2.88 /FemtoConstants::gevToFm;
        f0_si = 0.0  /FemtoConstants::gevToFm;
        d0_sr = 2.92 /FemtoConstants::gevToFm;
        d0_si = 0.0  /FemtoConstants::gevToFm;
        f0_tr = 1.66 /FemtoConstants::gevToFm;
        f0_ti = 0.0  /FemtoConstants::gevToFm;
        d0_tr = 3.78 /FemtoConstants::gevToFm;
        d0_ti = 0.0  /FemtoConstants::gevToFm;
        }
        else if (pairtype == 9) {
        f0_sr = -1.20 /FemtoConstants::gevToFm;
        f0_si = 0.37  /FemtoConstants::gevToFm;
        d0_sr = 0.0   /FemtoConstants::gevToFm;
        d0_si = 0.0   /FemtoConstants::gevToFm;
        f0_tr = -1.20 /FemtoConstants::gevToFm;
        f0_ti = 0.37  /FemtoConstants::gevToFm;
        d0_tr = 0.0   /FemtoConstants::gevToFm;
        d0_ti = 0.0   /FemtoConstants::gevToFm;
        }
        */
        if (rstar < 1.0 / FemtoConstants::gevToFm) 
            return 1.0;

        fr = f0_sr / (f0_sr * f0_sr + f0_si * f0_si);
        fi = -f0_si / (f0_sr * f0_sr + f0_si * f0_si);

        dr = 0.5 * d0_sr * kstar * kstar;

        ir = fr + dr;
        ii = fi - kstar;

        ar = ir / (ir * ir + ii * ii);
        ai = -ii / (ir * ir + ii * ii);

        srk = sin(kstar * rstar);
        crk = cos(kstar * rstar);

        sr = (ar * crk - ai * srk) / rstar;
        si = (ai * crk + ar * srk) / rstar;

        fr = f0_tr / (f0_tr * f0_tr + f0_ti * f0_ti);
        fi = -f0_ti / (f0_tr * f0_tr + f0_ti * f0_ti);

        dr = 0.5 * d0_tr * kstar * kstar;

        ir = fr + dr;
        ii = fi - kstar;

        ar = ir / (ir * ir + ii * ii);
        ai = -ii / (ir * ir + ii * ii);

        tr = (ar * crk - ai * srk) / rstar;
        ti = (ai * crk + ar * srk) / rstar;

        skr = sin(kstrst);
        ckr = cos(kstrst);

        return (0.25 * ((ckr + sr) * (ckr + sr) + (skr + si) * (skr + si)) + 0.75 * ((ckr + tr) * (ckr + tr) + (skr + ti) * (skr + ti)));
    }

    double TPIWeightGenerator::GetQuantumStrong() 
    {
        double fr, fi;
        double dr;
        double ar, ai;
        double ir, ii;

        double sgrp, sgip, sgrm, sgim;
        double trrp, trip, trrm, trim;

        double skr, ckr;
        double skm, ckm;
        double srk, crk;
        double srm, crm;

        //   double d0_sr;
        //   double d0_si;
        //   double d0_tr;
        //   double d0_ti;

        //   double f0_sr;
        //   double f0_si;
        //   double f0_tr;
        //   double f0_ti;

        double kstar  = fabs(fKStar);
        double rstar  = fRStarS;
        double kstrst = fKStarOut * fRStarOutS + fKStarSide * fRStarSideS + fKStarLong * fRStarLongS;

        //   std::cout << "k o s l " << kstar << " " << fKStarOut  << " " << fKStarSide << " " << fKStarLong << std::endl;
        //   std::cout << "r o s l " << fRStarS << " " << fRStarOutS  << " " << fRStarSideS << " " << fRStarLongS << std::endl;
        //   std::cout << "kr " << kstrst << std::endl;

        double snr, sni, trr, tri;

        double singlet, triplet;

        //   if (pairtype == 8) {
        //     f0_sr = 2.88 /FemtoConstants::gevToFm;
        //     f0_si = 0.0  /FemtoConstants::gevToFm;
        //     d0_sr = 2.92 /FemtoConstants::gevToFm;
        //     d0_si = 0.0  /FemtoConstants::gevToFm;
        //     f0_tr = 1.66 /FemtoConstants::gevToFm;
        //     f0_ti = 0.0  /FemtoConstants::gevToFm;
        //     d0_tr = 3.78 /FemtoConstants::gevToFm;
        //     d0_ti = 0.0  /FemtoConstants::gevToFm;
        //   }
        //   else if (pairtype == 9) {
        //     f0_sr = -1.20 /FemtoConstants::gevToFm;
        //     f0_si = 0.37  /FemtoConstants::gevToFm;
        //     d0_sr = 0.0   /FemtoConstants::gevToFm;
        //     d0_si = 0.0   /FemtoConstants::gevToFm;
        //     f0_tr = -1.20 /FemtoConstants::gevToFm;
        //     f0_ti = 0.37  /FemtoConstants::gevToFm;
        //     d0_tr = 0.0   /FemtoConstants::gevToFm;
        //     d0_ti = 0.0   /FemtoConstants::gevToFm;
        //   }

        if (rstar < 1.0 / FemtoConstants::gevToFm) 
            return 1.0;

        fr = fF0s.real() / (fF0s.real() * fF0s.real() + fF0s.imag() * fF0s.imag());
        fi = -fF0s.imag() / (fF0s.real() * fF0s.real() + fF0s.imag() * fF0s.imag());

        dr = 0.5 * fD0s.real() * kstar * kstar;

        ir = fr + dr;
        ii = fi - kstar;

        ar = ir / (ir * ir + ii * ii);
        ai = -ii / (ir * ir + ii * ii);

        srk = sin(kstar * rstar);
        crk = cos(kstar * rstar);

        sgrp = (ar * crk - ai * srk) / rstar;
        sgip = (ai * crk + ar * srk) / rstar;

        srm = sin(kstar * rstar);
        crm = cos(kstar * rstar);

        sgrm = (ar * crm - ai * srm) / rstar;
        sgim = (ai * crm + ar * srm) / rstar;

        skr = sin(kstrst);
        ckr = cos(kstrst);

        skm = sin(-kstrst);
        ckm = cos(-kstrst);

        snr = ckr + sgrp + ckm + sgrm;
        sni = skr + sgip + skm + sgim;

        singlet = 0.5 * (snr * snr + sni * sni);

        fr = fF0t.real() / (fF0t.real() * fF0t.real() + fF0t.imag() * fF0t.imag());
        fi = -fF0t.imag() / (fF0t.real() * fF0t.real() + fF0t.imag() * fF0t.imag());

        dr = 0.5 * fD0t.real() * kstar * kstar;

        ir = fr + dr;
        ii = fi - kstar;

        ar = ir / (ir * ir + ii * ii);
        ai = -ii / (ir * ir + ii * ii);

        trrp = (ar * crk - ai * srk) / rstar;
        trip = (ai * crk + ar * srk) / rstar;

        trrm = (ar * crm - ai * srm) / rstar;
        trim = (ai * crm + ar * srm) / rstar;

        trr = ckr + trrp - ckm - trrm;
        tri = skr + trip - skm - trim;

        triplet = 0.5 * (trr * trr + tri * tri);

        //   return (0.25 * ((ckr+sr)*(ckr+sr) + (skr+si)*(skr+si)) +
        //      0.75 * ((ckr+tr)*(ckr+tr) + (skr+ti)*(skr+ti)));

        //   std::cout << "sng tri full " << singlet << " "<< triplet << "  "  << (0.25 * singlet + 0.75 * triplet) << std::endl;

        return (0.25 * singlet + 0.75 * triplet);
    }

    double TPIWeightGenerator::GetQuantum() 
    {
        double quantumweight = 0;

        if (fTwospin == 0) 
        {
            quantumweight = 1.0 + cos(2.0 * (fKStarOut * fRStarOutS + fKStarSide * fRStarSideS + fKStarLong * fRStarLongS));
        } 
        else if (fTwospin == 1) 
        {
            if (fPcount == 3) 
            {
                quantumweight = 1.0 + cos(2.0 * (fKStarOut * fRStarOutS + fKStarSide * fRStarSideS + fKStarLong * fRStarLongS));
            } 
            else 
            {
                quantumweight = 1.0 - cos(2.0 * (fKStarOut * fRStarOutS + fKStarSide * fRStarSideS + fKStarLong * fRStarLongS));
            }
            fPcount++;
            if (fPcount == 4) 
                fPcount = 0;
        }

        return quantumweight;
    }

    std::complex<long double> TPIWeightGenerator::GetG(long double eta, long double rho, long double hfun) const 
    {
        std::complex<long double> gtemp;
        long double bres, pres;
        long double bmult;

        Bfunpfun(eta, rho, bres, pres);
        bmult = 2.0 * eta * rho * bres;

        gtemp = {pres + bmult * (log(fabs(2.0 * eta * rho)) + 2.0 * fEuler - 1.0 + hfun), bmult * Chiim(eta)};

        return gtemp;
    }

    void TPIWeightGenerator::Getfc(long double kstar, long double eta, long double hfun, std::complex<long double> &fcs, std::complex<long double> &fct) const 
    {
        std::complex<long double> ci;
        std::complex<long double> cia;

        std::complex<long double> fis;
        std::complex<long double> dis;
        std::complex<long double> fcinvs;

        std::complex<long double> fit;
        std::complex<long double> dit;
        std::complex<long double> fcinvt;

        ci = {hfun,Chiim(eta)};
        cia   = ci * static_cast<long double>(2.0 / fPionac);

        fis       = static_cast<long double>(1.) / fF0s;
        dis       = fD0s * static_cast<long double>(0.5 * kstar * kstar);
        fcinvs = fis + dis - cia;
        fcs       = static_cast<long double>(1.) / fcinvs;

        fit       = static_cast<long double>(1.) / fF0t;
        dit       = fD0t * static_cast<long double>(0.5 * kstar * kstar);
        fcinvt = fit + dit - cia;
        fct       = static_cast<long double>(1.) / fcinvt;
    }

    void TPIWeightGenerator::Bfunpfun(long double eta, long double rho, long double& bret, long double& pret) const 
    {
        long double b0   = 1;
        long double b1   = eta * rho;
        long double bsum = b0 + b1;
        long double bnpu, bn, bnmu;
        long double p0   = 1.0;
        long double p1   = 0.0;
        long double psum = p0 + p1;
        long double pnpu, pn, pnmu;

        if (rho > ROOT::Math::Pi() * 4.0) 
        {
            bret = sin(rho) / rho;
            pret = cos(rho);
            return;
        }

        bn   = b1;
        bnmu = b0;
        pn   = p1;
        pnmu = p0;
        for (int iter = 1; iter < 100000; iter++) 
        {
            bnpu = 2 * eta * rho * bn - rho * rho * bnmu;
            bnpu /= (1.0 * iter + 1.0) * (1.0 * iter + 2.0);
            bsum += bnpu;
            //    std::cout << "B E " << iter << " " << bnpu << std::endl;

            pnpu = 2 * eta * rho * pn - rho * rho * pnmu - (2.0 * iter + 1.0) * 2.0 * eta * rho * bn;
            pnpu /= (1.0 * iter) * (1.0 * iter + 1.0);
            psum += pnpu;
            //    std::cout << "P E " << iter << " " << pnpu << std::endl;

            bnmu = bn;
            bn   = bnpu;

            pnmu = pn;
            pn   = pnpu;
            if ((fabs(pnmu) + fabs(bnmu) + fabs(bnpu) + fabs(pnpu)) < 1.0e-20) 
            {
                //    std::cout << "iter " << iter << std::endl;
                break;
            }
        }


        bret = bsum;
        pret = psum;
    }

    long double TPIWeightGenerator::GetH(long double eta) const 
    {
        long double etasum = log(1.0 / eta) - fEuler;
        long double series = 0.0;
        long double x2inv  = (eta * eta);
        long double element;
        long double save;
        for (int iter = 1; iter < 1000000; iter++) 
        {
            element = ((1.0 * iter) * (1.0 * iter) + x2inv) * (1.0 * iter);
            //    std::cout << "Element " << iter << " is " << element << std::endl;
            element = 1.0 / element;
            if (iter == 1) 
                save = 1.0e-10 * element;
            //    std::cout << "Element " << iter << " is " << element << std::endl;

            series += element;
            if (element < save) 
                break;
        }
        series *= x2inv;
        etasum += series;

        return etasum;
    }

    double TPIWeightGenerator::GetCoulomb() 
    {
        double kstrst = fKStarOut * fRStarOutS + fKStarSide * fRStarSideS + fKStarLong * fRStarLongS;

        // Classical limit - if distance is larger than Coulomb radius,
        // the interaction does not matter
        if (fabs(fRStarS) > fabs(fPionac)) 
            return (1.0);
        if (fabs(fRStarS) == 0.0) 
            return (Gamow(fabs(fKStar)));

        // Classical limit - in the case of large k*r* product we go to
        // classical coulomb interaction
        if (fabs(fKStar) * fRStarS * (1.0 + kstrst / (fRStarS * fabs(fKStar))) > 15.0)
            return (1.0 - 1.0 / (fRStarS * fPionac * fKStar * fKStar));

        // Calculate the F function
        std::complex<long double> ffplus;
        GetFFsingle(ffplus);

        if (!finite(ffplus.real())) 
        {
            std::cout << "FFPlus Re not a number !" << " " << std::endl;
            std::cout << fRStarS << " " << fKStar << " " << fRStarOutS << " " << fRStarSideS << " " << fRStarLongS << std::endl;
        }

        if (!finite(ffplus.imag()))
            std::cout << "FFPlus Im not a number !" << " " << std::endl;

        return (Gamow(fabs(fKStar)) * norm(ffplus));
    }

    double TPIWeightGenerator::GetQuantumCoulomb() 
    {
        if (fRStarS < 0.0000000001) 
            return 1.0;

        double kstrst = fKStarOut * fRStarOutS + fKStarSide * fRStarSideS + fKStarLong * fRStarLongS;
        int ccase     = 0;
        int wavesign  = 1;

        if (fTwospin == 1) 
        {
            if (fPcount == 3)
                wavesign = 1;
            else
                wavesign = -1;
            fPcount++;
            if (fPcount == 4) 
                fPcount = 0;
        }

        // Classical limit - if distance is larger than Coulomb radius,
        // the interaction does not matter
        if (fabs(fRStarS) > fabs(fPionac)) 
            return (1.0 + wavesign * cos(2 * kstrst));

        // Classical limit - in the case of large k* we go to
        // classical coulomb interaction
        long double testp = fabs(fKStar) * fRStarS * (1.0 + kstrst / (fRStarS * fabs(fKStar)));
        long double testm = fabs(fKStar) * fRStarS * (1.0 - kstrst / (fRStarS * fabs(fKStar)));

        if ((testp > 15.0) && (testm > 15.0)) 
        {
            double fasymplus  = (1.0 - 1.0 / ((fRStarS + kstrst) * fPionac * fKStar * fKStar));
            double fasymminus = (1.0 - 1.0 / ((fRStarS - kstrst) * fPionac * fKStar * fKStar));
            return 0.5 * ((fasymplus + fasymminus) * cos(2 * kstrst) + (2.0 * sqrt(fasymplus * fasymminus)));
        }
        //    return (1.0 - 1.0/(fRStarS*pionac*fKStar*fKStar))*(1.0+wavesign*cos(2*kstrst));

        std::complex<long double> ffplus, ffminus;
        // Check for the classical limit in both functions separately
        if (((testp < 15.0) && (testm < 15.0)))  // ||
                                                //       ((testp< 15.0) && (testm> 15.0) && (fabs(testp-testm < 1.0))) ||
                                                //       ((testp> 15.0) && (testm< 15.0) && (fabs(testp-testm < 1.0))))
        {
            // Calculate the F function
            GetFFdouble(ffplus, ffminus);
            ccase = 1;
        } 
        else if (testp < 15.0) 
        {
            double asym;
            GetFFsingle(ffplus);
            //      GetFFsingle(&ffminus,-1);
            asym =
                (1.0 - 1.0 / (fRStarS * (1.0 - kstrst / (fRStarS * fabs(fKStar)) * fPionac * fKStar * fKStar))) / Gamow(fabs(fKStar));
            asym = sqrt(asym);
            if (asym < 1.0)
                asym = 1.0 + (asym - 1.0) * 2.0;
            else
                asym = 1.0 + (asym - 1.0) / 2.0;

            ffminus.real(asym);
            ffminus = {asym,sqrt(asym * asym - ffminus.real() * ffminus.real())};
            ccase      = 2;
        } 
        else 
        {
            double asym;
            //      GetFFsingle(&ffplus);
            GetFFsingle(ffminus, -1);
            asym = (1.0 - 1.0 / (fRStarS * (1.0 + kstrst / (fRStarS * fabs(fKStar)) * fPionac * fKStar * fKStar))) / Gamow(fabs(fKStar));
            asym = sqrt(asym);
            if (asym < 1.0)
                asym = 1.0 + (asym - 1.0) * 2.0;
            else
                asym = 1.0 + (asym - 1.0) / 2.0;

            ffplus.real(asym);
            ffplus = {asym,sqrt(asym * asym - ffplus.real() * ffplus.real())};
            ccase = 3;
        }

        std::complex<long double> expikr(cos(kstrst),sin(kstrst));

        std::complex<long double> expikrc = conj(expikr);
        std::complex<long double> ffplusc = conj(ffplus);
        std::complex<long double> ffminusc = conj(ffminus);

        std::complex<long double> expikr2 = expikr * expikr;
        std::complex<long double> expikrc2 = conj(expikr2);
        std::complex<long double> sterm = expikr2 * ffplus * ffminusc;
        std::complex<long double> tterm = expikrc2 * ffminus * ffplusc;


        if (!finite(ffminus.real()))
        std::cout << "FFMinus Re not a number !" << " " << ccase << std::endl;

        if (!finite(ffminus.imag()))
        std::cout << "FFMinus Im not a number !" << " " << ccase << std::endl;

        if ((ffplus.real() > 2.0) || (ffplus.real() < -2.0)) 
            std::cout << std::endl << "FFplus Re wild !" << ffplus.real() << std::endl;

        if ((ffplus.imag() > 2.0) || (ffplus.imag() < -2.0)) 
            std::cout << "FFplus Im wild !" << ffplus.imag() << std::endl;

        if ((ffminus.real() > 2.0) || (ffminus.real() < -2.0))
            std::cout << std::endl << "FFminus Re wild !" << ffminus.real() << " " << ccase << std::endl;

        if ((ffminus.imag() > 2.0) || (ffminus.imag() < -2.0)) 
            std::cout << "FFminus Im wild !" << ffminus.imag() << " " << ccase << std::endl;

        fCoulqscpart = 0.5 * Gamow(fabs(fKStar)) * (norm(ffplus) + norm(ffminus));

        return (0.5 * Gamow(fabs(fKStar)) * (norm(ffplus) + wavesign * sterm.real() + wavesign * tterm.real() + norm(ffminus)));
    }

    void TPIWeightGenerator::GetFFdouble(std::complex<long double> &ffp, std::complex<long double> &ffm) const 
    {
        long double comprep[fCoulombSteps]; // this is wrong on so many levels I can't even comprehend - JJ
        long double compimp[fCoulombSteps];
        long double comprem[fCoulombSteps];
        long double compimm[fCoulombSteps];
        long double eta, ksip, ksim;
        std::complex<long double> alfa, zetp, zetm;

        int nsteps;

        long double kstar  = fabs(fKStar);
        long double kstrst = fKStarOut * fRStarOutS + fKStarSide * fRStarSideS + fKStarLong * fRStarLongS;
        long double coskr  = kstrst / (fabs(fKStar) * fRStarS);

        if ((kstar * fRStarS * (1 + coskr) < 5.0) && (kstar * fRStarS * (1 - coskr) < 5.0))
            nsteps = 25;
        else if ((kstar * fRStarS * (1 + coskr) < 10.0) && (kstar * fRStarS * (1 - coskr) < 10.0))
            nsteps = 45;
        else if ((kstar * fRStarS * (1 + coskr) < 15.0) && (kstar * fRStarS * (1 - coskr) < 15.0))
            nsteps = 110;
        else
            nsteps = 150;

        eta = 1.0 / (kstar * fPionac);
        alfa = {0.0,-eta};

        std::complex<long double> fcomp, scompp, scompm;
        long double tcomp;
        std::complex<long double> sump, summ;
        std::complex<long double> fcmult;

        long double rad = fRStarS;

        ksip = kstar * rad * (1 + coskr);
        ksim = kstar * rad * (1 - coskr);

        zetp = {0.0,ksip};

        zetm = {0.0,ksim};

        fcomp = 1.0;
        scompp = 1.0;
        scompm = 1.0;
        tcomp = 1.0;

        for (int istep = 0; istep < nsteps; istep++) 
        {
            sump = fcomp * scompp;
            summ = fcomp * scompm;

            sump = sump / (tcomp * tcomp);
            summ = summ / (tcomp * tcomp);


            if (istep == 0) 
            {
                comprep[istep] = sump.real();
                compimp[istep] = sump.imag();

                comprem[istep] = summ.real();
                compimm[istep] = summ.imag();
            } 
            else 
            {
                comprep[istep] = comprep[istep - 1] + sump.real();
                compimp[istep] = compimp[istep - 1] + sump.imag();

                comprem[istep] = comprem[istep - 1] + summ.real();
                compimm[istep] = compimm[istep - 1] + summ.imag();
            }

            fcmult = {alfa.real() + istep, alfa.imag()};

            fcomp  = fcomp * fcmult;
            scompp = scompp * zetp;
            scompm = scompm * zetm;
            tcomp *= (istep + 1);
        }

        ffp = {comprep[nsteps - 1], compimp[nsteps - 1]};
        ffm = {comprem[nsteps - 1], compimm[nsteps - 1]};
    }

    void TPIWeightGenerator::GetFFsingle(std::complex<long double> &ffp, int sign) const 
    {
        double comprep[fCoulombSteps];
        double compimp[fCoulombSteps];
        double eta, ksip;
        std::complex<long double> alfa, zetp;

        int nsteps;

        double kstar  = fabs(fKStar);
        double kstrst = fKStarOut * fRStarOutS + fKStarSide * fRStarSideS + fKStarLong * fRStarLongS;
        double coskr  = sign * kstrst / (fabs(fKStar) * fRStarS);

        if (kstar * fRStarS * (1 + coskr) > 15.0)
            nsteps = 170;
        else if (kstar * fRStarS * (1 + coskr) > 10.0)
            nsteps = 45;
        else if (kstar * fRStarS * (1 + coskr) > 5.0)
            nsteps = 35;
        else
            nsteps = 15;

        eta     = 1.0 / (kstar * fPionac);
        alfa = {0.0,-eta};

        std::complex<long double> fcomp, scompp;
        long double tcomp;
        std::complex<long double> sump;
        std::complex<long double> fcmult;

        double rad = fRStarS;

        ksip = kstar * rad * (1 + coskr);

        zetp = {0.0,ksip};

        fcomp = 1.0;
        scompp = 1.0;
        tcomp = 1.0;

        for (int istep = 0; istep < nsteps; istep++) 
        {
            sump = fcomp * scompp;

            sump = sump / (tcomp * tcomp);

            if (istep == 0) 
            {
                comprep[istep] = sump.real();
                compimp[istep] = sump.imag();
            } 
            else 
            {
                comprep[istep] = comprep[istep - 1] + sump.real();
                compimp[istep] = compimp[istep - 1] + sump.imag();
            }

            fcmult = {alfa.real() + istep,alfa.imag()};

            fcomp  = fcomp * fcmult;
            scompp = scompp * zetp;
            tcomp *= (istep + 1);

            if ((sump.real() * sump.real() + sump.imag() * sump.imag()) < 1.0e-14) // another arbitrary small number (at lest be consistent for God's sake) - JJ
            {
                nsteps = istep;
                break;
            }
        }

        ffp = {comprep[nsteps - 1],compimp[nsteps - 1]};
    }
} // namespace Opossum
