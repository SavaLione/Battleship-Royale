#include "Regex.h"

#include <string>

#include <boost/regex.hpp>

#include "BattleshipRoyale.h"

bool check_pattern(std::string *msg, std::string *pattern)
{
    boost::regex pat(*pattern);
    boost::smatch result;
    return boost::regex_search(*msg, result, pat);
}