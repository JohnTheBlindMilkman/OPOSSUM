/**
 * @file TPIWeightGenerator.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Implementation of the correlation function weight algorithm from Adam Kisiel's TPI package
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TPIWeightGenerator_h
    #define TPIWeightGenerator_h

    #include <complex>
    #include "WeightGenerator.h"
    #include "FemtoConstants.hxx"

    namespace Opossum
    {
        class TPIWeightGenerator : public WeightGenerator
        {
            private:
                /**
                 * Calculates the confluent hypergeometric function F from single orientation of cos(theta*) for non-symmetrized wave-function
                 * (non-identical particles)
                 * @param ffp
                 * @param sign
                 */
                void GetFFsingle(std::complex<long double> &ffp, int sign = 1) const;
                /**
                 * Calculates the confluent hypergeometric function for two orientations of cos(theta*) for symmetrized wave-function
                 * (identical particles)
                 * @param ffp
                 * @param ffm
                 */
                void GetFFdouble(std::complex<long double> &ffp, std::complex<long double> &ffm) const;
                /**
                 * Calculates G~ function
                 * @param eta
                 * @param rho
                 * @param hfun
                 * @return
                 */
                std::complex<long double> GetG(long double eta, long double rho, long double hfun) const;
                long double Chiim(long double eta) const;
                /**
                 * Calculates H function for strong interaction
                 * @param eta
                 * @return
                 */
                long double GetH(long double eta) const;
                void Getfc(long double kstar, long double eta, long double hfun, std::complex<long double> &fcs, std::complex<long double> &fct) const;  // TODO
                void Bfunpfun(long double eta, long double rho, long double &bret, long double &pret) const;
                double Funeh(double xarg, double rad, double alfa) const;
                double Funex(double xarg, double rad) const;
                void InitializeGamow();
                void PairKinematics(const PairCandidate &pair);
                double GetCoulomb();
                double Gamow(double arg) const;
                double GetQuantumCoulombStrong();
                double GetCoulombStrong();
                double GetQuantumStrong();
                double GetStrong();
                double GetQuantum();
                /**
                 * @brief Calculates weight for identical bosons
                 * 
                 * @return double
                 */
                double GetQuantumCoulomb();

                FemtoConstants::PairType fPairType;
                std::complex<long double> fD0s, fF0s, fD0t, fF0t;
                long double fPionac, fOneoveracsq, fTwopioverac, fCoulqscpart, fEuler, fF0, fD0;
                int fTwospin, fWritegrps, fPcount, fCoulombSteps;
                double fRStarOutS, fRStarSideS, fRStarLongS, fRStarS, fRStarLong, fRStarOut, fRStarSide, fRStar, fKStarLong, fKStarOut, fKStarSide, fKStar;

            public:
                /**
                 * @brief Construct a new TPIWeightGenerator object
                 * 
                 */
                TPIWeightGenerator();
                /**
                 * @brief Destroy the TPIWeightGenerator object
                 * 
                 */
                virtual ~TPIWeightGenerator() = default;
                /**
                 * @brief Calculate the weight for given PairCandidate object
                 * 
                 * @param pair 
                 * @return double 
                 */
                double CalculateWeight(const PairCandidate &pair) override;
        };

        inline long double TPIWeightGenerator::Chiim(long double eta) const { return Gamow(1.0 / (eta * fPionac)) / (2.0 * eta); }
        inline double TPIWeightGenerator::Funeh(double xarg, double rad, double alfa) const { return exp(-sqrt(xarg * xarg / (rad * rad) + alfa * alfa)); }
        inline double TPIWeightGenerator::Funex(double xarg, double rad) const { return exp(-xarg / rad); }
    }

#endif