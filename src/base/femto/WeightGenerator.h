/**
 * @file WeightGenerator.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Bas class for implementing the correlation function weight algorithm of choice
 * @version 0.1
 * @date 2023-12-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef WeightGenerator_h
    #define WeightGenerator_h

    #include "../../selection/PairCandidate.h"
    #include "FemtoConstants.hxx"

    namespace Opossum
    {
        class WeightGenerator
        {
            private:

            public:
                /**
                 * @brief Construct a new Weight Generator object (placeholder c-tor)
                 * 
                 */
                WeightGenerator() {}
                /**
                 * @brief Destroy the Weight Generator object (placeholder destructor)
                 * 
                 */
                virtual ~WeightGenerator() {}
                /**
                 * @brief Calculate the weight for given pair (placeholder method)
                 * 
                 * @return double weight
                 */
                virtual double CalculateWeight(const PairCandidate &) {return 0.0;}
                /**
                 * @brief Check if given pair combination is suported by the generator (placeholder method)
                 * 
                 * @return true 
                 * @return false 
                 */
                virtual bool PairIsSuported(const PairCandidate &) const {return false;}
        };
    }

#endif