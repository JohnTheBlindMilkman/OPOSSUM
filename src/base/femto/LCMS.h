/**
 * @file LCMS.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Reference frame class of Longitudinally Co-Moving System (LCMS)
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LCMS_h
    #define LCMS_h

    #include <tuple>
    #include <string>
    #include "../../selection/PairCandidate.h"

    namespace Opossum
    {
        class LCMS
        {
            private:
                std::string fName, fXAxisDesc, fYAxisDesc, fZAxisDesc, fSingleAxisDesc;
                float fX, fY, fZ, fT, fPx, fPy, fPz, fE, fKt;
                
            public:
                /**
                 * @brief Construct a new LCMS object
                 * 
                 */
                LCMS();
                /**
                 * @brief Destroy the LCMS object
                 * 
                 */
                ~LCMS() = default;
                /**
                 * @brief Returns decomposed momentum in the LCMS reference frame
                 * 
                 * @param pair PairCandidate object
                 * @return std::tuple<float,float,float,float> 
                 */
                void Calculate(const PairCandidate &pair);
                /**
                 * @brief Returns std::tuple with 4-momentum components of the pair in the LCMS reference frame in the form of (Px,Py,Pz,E)
                 * 
                 * @return constexpr std::tuple<float,float,float,float> 
                 */
                constexpr std::tuple<float,float,float,float> Get4Momentum() {return std::make_tuple(fPx,fPy,fPz,fE);}
                /**
                 * @brief Returns std::tuple with 4-position components of the pair in the LCMS reference frame in the form of (X,Y,Y,T)
                 * 
                 * @return constexpr std::tuple<float,float,float,float> 
                 */
                constexpr std::tuple<float,float,float,float> Get4Positions() {return std::make_tuple(fX,fY,fZ,fT);}
                /**
                 * @brief Get the Kt
                 * 
                 * @return constexpr float 
                 */
                constexpr float GetKt() {return fKt;}
                /**
                 * @brief Get the Name of the reference frame
                 * 
                 * @return std::string 
                 */
                inline std::string GetName() const {return fName;}
                /**
                 * @brief Returns X-axis label for ROOT 3D histograms
                 * 
                 * @return std::string 
                 */
                inline std::string GetXAxisTitle() const {return fXAxisDesc;}
                /**
                 * @brief Returns Y-axis label for ROOT 3D histograms
                 * 
                 * @return std::string 
                 */
                inline std::string GetYAxisTitle() const {return fYAxisDesc;}
                /**
                 * @brief Returns Z-axis label for ROOT 3D histograms
                 * 
                 * @return std::string 
                 */
                inline std::string GetZAxisTitle() const {return fZAxisDesc;}
                /**
                 * @brief Returns X-axis label for ROOT 1D histograms
                 * 
                 * @return std::string 
                 */
                inline std::string GetSingleAxisTitle() const {return fSingleAxisDesc;}
        };
    } // namespace Opossum

#endif