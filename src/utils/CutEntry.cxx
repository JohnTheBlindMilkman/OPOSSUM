#include "CutEntry.h"

namespace Opossum
{
    void from_json(const nlohmann::json &j, CutEntry &c)
        {
            c.tag = j["tag"];

            auto jLt = j["less_than"];
            if (jLt.is_number_integer())
                c.less_than = jLt.get<long int>();
            else if (jLt.is_number_float())
                c.less_than = jLt.get<float>();

            auto jEq = j["equal"];
            if (jEq.is_number_integer())
                c.equal = jEq.get<long int>();
            else if (jEq.is_number_float())
                c.equal = jEq.get<float>();

            auto jMt = j["more_than"];
            if (jMt.is_number_integer())
                c.more_than = jMt.get<long int>();
            else if (jMt.is_number_float())
                c.more_than = jMt.get<float>();
        }
} // namespace Opossum