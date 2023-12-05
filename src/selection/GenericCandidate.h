/**
 * @file GenericCandidate.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Base class for a candidate object. It defines haw candidates get selected.
 * @version 0.1
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GenericCandidate_h
    #define GenericCandidate_h

    #include <iostream>
    #include "../utils/ConfigParser.h"

    namespace Opossum
    {
        template<typename EnumType>
        class GenericCandidate
        {
            private:
                Relation ValueComp(const std::variant<long int, float> &value, const std::variant<long int, float> &cutoff)
                {
                    try
                    {
                        if (value == cutoff)
                            return Relation::Equal;
                        else if (value < cutoff)
                            return Relation::Less;
                        else if (value > cutoff)
                            return Relation::More;
                    }
                    catch(std::bad_variant_access&)
                    {
                        std::cerr << "GenericCandidate::VauleComp - Incompatibale variant comparison \n";
                    }
                }
            protected:
                std::unordered_map<EnumType,std::variant<long int, float> > fObservables;

            public:
                /**
                 * @brief Construct a new Generic Candidate object
                 * 
                 */
                GenericCandidate() = default;
                /**
                 * @brief Destroy the Generic Candidate object
                 * 
                 */
                virtual ~GenericCandidate() = default;
                /**
                 * @brief Perform relation operation on passed map and the observable map
                 * 
                 * @tparam EnumType 
                 * @return true - Passed
                 * @return false - Rejected
                 */
                bool Select(const std::unordered_map<EnumType,CutEntry> &cutMap)
                {
                    for (const auto &cut : cutMap)
                    {
                        if (cut.second.more_than && cut.second.less_than)
                        {
                            if ((fObservables[cut.first] < cut.second.more_than.value()) || (fObservables[cut.first] < cut.second.less_than.value()))
                                return false;
                        }
                        else if (cut.second.equal)
                        {
                            if (fObservables[cut.first] != cut.second.equal.value())
                                return false;
                        }
                    }

                    return true;
                }
        };
    }

#endif