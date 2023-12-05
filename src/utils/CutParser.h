/**
 * @file CutParser.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Parser for selection.json cut setting file
 * @version 0.1
 * @date 2023-11-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef CutParser_h
    #define CutParser_h

    #include <string>

    #include "../selection/ObservableList.h"
    #include "CutEntry.h"

    namespace Opossum
    {
        class CutParser
        {
            private:
                nlohmann::json_abi_v3_11_2::json fJson;
                const std::map<std::string,EventObservable> fEventLut;
                const std::map<std::string,TrackObservable> fTrackLut;
                const std::map<std::string,PairObservable> fPairLut;

            public:
                /**
                 * @brief Construct a new Cut Parser object
                 * 
                 */
                CutParser();
                /**
                 * @brief Destroy the Cut Parser object
                 * 
                 */
                ~CutParser();
                /**
                 * @brief Converts the selection.json file from nlohmann::json format to std::unordered_map for particle selection
                 * 
                 * @tparam EnumType 
                 * @param json - parsed selection.json file with key "eventCut", "trackCut" or "pairCut"
                 * @return std::unordered_map<EnumType,CutEntry> - map of cuts requested by the user
                 */
                template <typename EnumType> std::unordered_map<EnumType,CutEntry> ConvertFromJson(nlohmann::json_abi_v3_11_2::json &json)
                {
                    std::unordered_map<EnumType,CutEntry> lut;
                    CutEntry element;
                    std::map<std::string,EnumType> cutNameMapping;

                    if constexpr (std::is_same<EnumType,EventObservable>::value)
                        cutNameMapping = fEventLut;
                    else if constexpr (std::is_same<EnumType,TrackObservable>::value)
                        cutNameMapping = fTrackLut;
                    else if constexpr (std::is_same<EnumType,PairObservable>::value)
                        cutNameMapping = fPairLut;
                    else
                        throw std::runtime_error("CutParser::ConvertFromJson - undefined cut type");

                    for (const auto &entry : json)
                    {
                        element = entry.get<CutEntry>();

                        if (cutNameMapping.end() != cutNameMapping.find(element.tag))
                            lut[cutNameMapping[element.tag]] = element;
                    }

                    return lut;
                } 
        };
    } // namespace name

#endif