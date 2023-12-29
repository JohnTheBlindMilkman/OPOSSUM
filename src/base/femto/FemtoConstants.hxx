/**
 * @file FemtoConstants.hxx
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Collection of femtoscopy related constants and LUTs
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef FemtoConstants_hxx
    #define FemtoConstants_hxx

    #include <unordered_map>

    namespace Opossum
    {
        struct pair_hash 
        {
            std::size_t operator()(const std::pair<long int,long int> &p) const 
            {
                auto h1 = std::hash<long int>{}(p.first);
                auto h2 = std::hash<long int>{}(p.second);

                // Mainly for demonstration purposes, i.e. works but is overly simple
                // In the real world, use sth. like boost.hash_combine
                return h1 ^ (h2 << 1); 
            }
        };

        namespace FemtoConstants
        {
            enum class PairType 
            {
                Unknown,
                PionPlusPionPlus,
                PionPlusPionMinus,
                KaonPlusKaonPlus,
                KaonPlusKaonMinus,
                ProtonProton,
                ProtonAntiproton,
                PionPlusKaonPlus,
                PionPlusKaonMinus,
                PionPlusProton,
                PionPlusAntiproton,
                KaonPlusProton,
                KaonPlusAntiproton,
                ProtonLambda,
                LambdaLambda,
                KaonZeroKaonZero,
                KaonZeroKaonZeroBar,
                NeutronNeutron,
                NeutronProton,
                PionZeroPionZero,
                NeutronLambda,
                ProtonSigmaPlus,
                ProtonAntiSigmaPlus,
                ProtonAntiLambda,
                SigmaPlusSigmaPlus,
                SigmaPlusAntiSigmaPlus,
                ProtonXiZero,
                NeutronXiMinus,
                ProtonXiMinus,
                NeutronXiZero,
                ProtonSigmaZero,
                SigmaZeroSigmaZero,
                LambdaSigmaZero,
                LambdaAntiLambda
            };

            // wish this could be constexpr... - JJ
            // storing possible combinations of pairs for easier management what is what for the whole femto part
            static const std::unordered_map<std::pair<long int,long int>, PairType, pair_hash> pairMap 
            {
                {{211,211},PairType::PionPlusPionPlus},
                {{211,-211},PairType::PionPlusPionMinus},
                {{-211,211},PairType::PionPlusPionMinus},
                {{321,321},PairType::KaonPlusKaonPlus},
                {{321,-321},PairType::KaonPlusKaonMinus},
                {{-321,321},PairType::KaonPlusKaonMinus},
                {{2212,2212},PairType::ProtonProton},
                {{2212,-2212},PairType::ProtonAntiproton},
                {{-2212,2212},PairType::ProtonAntiproton},
                {{221,321},PairType::PionPlusKaonPlus},
                {{321,221},PairType::PionPlusKaonPlus},
                {{221,-321},PairType::PionPlusKaonMinus},
                {{-321,221},PairType::PionPlusKaonMinus},
                {{221,2212},PairType::PionPlusProton},
                {{2212,221},PairType::PionPlusProton},
                {{221,-2212},PairType::PionPlusAntiproton},
                {{-2212,221},PairType::PionPlusAntiproton},
                {{321,2212},PairType::KaonPlusProton},
                {{2212,321},PairType::KaonPlusProton},
                {{321,-2212},PairType::KaonPlusAntiproton},
                {{-2212,321},PairType::KaonPlusAntiproton},
                {{3122,2212},PairType::ProtonLambda},
                {{2212,3122},PairType::ProtonLambda},
                {{3122,3122},PairType::LambdaLambda},
                {{310,310},PairType::KaonZeroKaonZero},
                {{310,-310},PairType::KaonZeroKaonZeroBar},
                {{-310,310},PairType::KaonZeroKaonZeroBar},
                {{2112,2112},PairType::NeutronNeutron},
                {{2212,2112},PairType::NeutronProton},
                {{2112,2212},PairType::NeutronProton},
                {{111,111},PairType::PionZeroPionZero},
                {{3122,2112},PairType::NeutronLambda},
                {{2112,3122},PairType::NeutronLambda},
                {{3222,2212},PairType::ProtonSigmaPlus},
                {{2212,3222},PairType::ProtonSigmaPlus},
                {{-3222,2212},PairType::ProtonAntiSigmaPlus},
                {{2212,-3222},PairType::ProtonAntiSigmaPlus},
                {{-3122,2212},PairType::ProtonAntiLambda},
                {{2212,-3122},PairType::ProtonAntiLambda},
                {{3222,3222},PairType::SigmaPlusSigmaPlus},
                {{3222,-3222},PairType::SigmaPlusAntiSigmaPlus},
                {{-3222,3222},PairType::SigmaPlusAntiSigmaPlus},
                {{2212,3322},PairType::ProtonXiZero},
                {{3322,2212},PairType::ProtonXiZero},
                {{2112,3312},PairType::NeutronXiMinus},
                {{3312,2112},PairType::NeutronXiMinus},
                {{2212,3312},PairType::ProtonXiMinus},
                {{3312,2212},PairType::ProtonXiMinus},
                {{2112,3322},PairType::NeutronXiZero},
                {{3322,2112},PairType::NeutronXiZero},
                {{2212,3212},PairType::ProtonSigmaZero},
                {{3212,2212},PairType::ProtonSigmaZero},
                {{3212,3212},PairType::SigmaZeroSigmaZero},
                {{3122,3212},PairType::LambdaSigmaZero},
                {{3212,3122},PairType::LambdaSigmaZero},
                {{3122,-3122},PairType::LambdaAntiLambda},
                {{-3122,3122},PairType::LambdaAntiLambda}
            };

            constexpr float fmToGev = 5.06842372;
            constexpr float gevToFm = 0.197327;

            constexpr float gevToMev = 1000.;
        } // namespace FemtoConstants
           
    }

#endif