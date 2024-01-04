/**
 * @file CF1D.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Class for one dimensional correlation function object
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef CF1D_h
    #define CF1D_h

    #include "CF.h"
    #include "TH1D.h"

    namespace Opossum
    {
        template<typename T>
        class CF1D : public CF<T>
        {
            private:
                TH1D fCFHistogram;

            public:
                /**
                 * @brief Construct a new CF1D object
                 * 
                 */
                CF1D() : fCFHistogram("CF1D","",300,0,3.0) 
                {
                    CF<T>::fCorrectionFunction = [](const PairCandidate &pair){return pair;};
                }
                /**
                 * @brief Destroy the CF1D object
                 * 
                 */
                ~CF1D() {}
                /**
                 * @brief Apply desired correction for each PairCandidate object contained within the correlation function
                 * 
                 * @param correctionFunction any std::function castable object (function, lambda expression or bind expression)
                 * @exception std::bad_funtion_call If std::function contains no taget
                 */
                void ApplyCorrection(std::function<PairCandidate(const PairCandidate&)> &&correctionFunction) override
                {
                    CF<T>::fCorrectionFunction = std::move(correctionFunction);
                }
                /**
                 * @brief Fill histogram with given PairCandidate object
                 * 
                 * @param pair PairCandidate
                 * @param weight femtoscopic weight calculated in the WeightGenerator class implementations
                 */
                void AddPair(const PairCandidate &pair, const double &weight) override
                {
                    CF<T>::fFrameOfReference.Calculate(CF<T>::fCorrectionFunction(pair));
                    fCFHistogram.Fill(std::get<3>(CF<T>::fFrameOfReference.Get4Momentum()),weight);
                }
        };

    } // namespace Opossum
    

#endif