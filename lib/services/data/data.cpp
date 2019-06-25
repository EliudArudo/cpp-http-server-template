#include <string>
#include <map>

#include "data.h"
#include "../../nlohmann/json.hpp"

using nlohmann::json;

std::string DataService::mapToString(std::map<std::string, std::string> victim)
{
    std::string result;

    json jmap(victim);
    return jmap.dump(4); // '4' there is for nice indentation
};