/**
 * @file CF.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Base class for correlation function objects
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef CF_h
    #define CF_h

    #include "../../selection/PairCandidate.h"
    #include <functional>
    #include <type_traits>

    namespace Opossum
    {
        // I wanted to make sure the user knows the reference frame has to have this method - JJ
       /*  struct has_calculate_momentum_impl 
        {
            template<typename T, typename Method = decltype(std::declval<const T&>().CalculateMomentum())>
            static std::true_type test(int);
            template<typename...>
            static std::false_type test(...);
        };

        template<typename T>
        struct has_calculate_momentum : decltype(has_calculate_momentum_impl::test<T>(0)) {}; */

        template <typename T>
        class CF
        {
            //static_assert(has_calculate_momentum<T>::value,"CF<T> - template class T does not contain CalculateMomentum() method");

            private:

            protected:
                

            public:
                /**
                 * @brief Construct the CF object
                 * 
                 */
                CF(/* args */) = default;
                /**
                 * @brief Destroy the CF object
                 * 
                 */
                virtual ~CF() = default;
                /**
                 * @brief Apply desired correction for each PairCandidate object contained within the correlation function
                 * 
                 * @param correctionFunction any std::function castable object (function, lambda expression or bind expression)
                 * @exception std::bad_funtion_call If std::function contains no taget
                 */
                virtual void ApplyCorrection(std::function<PairCandidate(const PairCandidate&)> &&correctionFunction) {}
                /**
                 * @brief Fill histogram with given PairCandidate object
                 * 
                 * @param pair PairCandidate
                 * @param weight femtoscopic weight calculated in the WeightGenerator class implementations
                 */
                virtual void AddPair(const PairCandidate &pair, const double &weight) {}

                std::function<PairCandidate(const PairCandidate&)> fCorrectionFunction;
                T fFrameOfReference;
        };
    } // namespace Opossum

#endif