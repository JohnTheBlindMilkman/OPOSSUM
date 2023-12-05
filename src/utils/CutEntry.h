/**
 * @file CutEntry.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief The class containing the cut entry object whic is read from the selection.json file.
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef CutEntry_h
    #define CutEntry_h

    #include "json.hpp"
    #include <variant>
    #include <optional>

    // required by the nlohmann::json to work with std::optional
    // partial specialization (full specialization works too)
    namespace nlohmann
    {
        template <typename T>
        struct adl_serializer<std::optional<T> >
        {
            static void to_json(json& j, const std::optional<T> & opt)
            {
                if (opt == std::nullopt) {
                    j = nullptr;
                } else {
                j = *opt;
                }
            }

            static void from_json(const json& j, std::optional<T> & opt)
            {
                if (j.is_null()) {
                    opt = std::nullopt;
                } else {
                    opt = j.get<T>();
                }
            }
        };
    }

    namespace Opossum
    {
        struct CutEntry
        {
            std::string tag = "";
            std::optional<std::variant<long int, float> > less_than;
            std::optional<std::variant<long int, float> > equal;
            std::optional<std::variant<long int, float> > more_than;
        };

        void from_json(const nlohmann::json &j, CutEntry &c);
    }

#endif