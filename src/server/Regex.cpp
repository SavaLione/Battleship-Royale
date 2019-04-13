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

void getData(std::string *msg, std::string *pattern, std::string *ret_one)
{
    boost::regex pat(*pattern);
    boost::smatch result;
    if (boost::regex_search(*msg, result, pat))
    {
        std::string submatch_one(result[1].first, result[1].second);
        *ret_one = submatch_one;
    }
}

void getData(std::string *msg, std::string *pattern, std::string *ret_one, std::string *ret_two)
{
    boost::regex pat(*pattern);
    boost::smatch result;
    if (boost::regex_search(*msg, result, pat))
    {
        std::string submatch_one(result[1].first, result[1].second);
        std::string submatch_two(result[2].first, result[2].second);
        *ret_one = submatch_one;
        *ret_two = submatch_two;
    }
}