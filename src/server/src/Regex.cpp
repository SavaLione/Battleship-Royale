/**
 * @file
 * @brief Работа с регулярными выражениями
 * @author SavaLione
 * @date 13 Apr 2019
 */
/**
 * @defgroup regexcpp Regex.cpp
 * @ingroup server
 * @{
 */
#include "Regex.h"

#include <string>

#include <boost/regex.hpp>

#include "BattleshipRoyale.h"

/**
 * @brief Проверка соответствия строки паттерну
 * @code
 *      string s = "user:[SavaLione]";
 *      string s_pattern = BR::REG_USER;
 *      if(check_pattern(&s, &s_pattern))
 *      {
 *          //some
 *      }
 * @endcode
 * @param [in] msg Строка
 * @param [in] pattern Паттерн
 * @return true - соответствует, false - не соответствует.
 */
bool check_pattern(std::string *msg, std::string *pattern)
{
    boost::regex pat(*pattern);
    boost::smatch result;
    return boost::regex_search(*msg, result, pat);
}

/**
 * @brief Получение информации из строки
 * @code
 *      string s = "user:[SavaLione]";
 *      string s_pattern = BR::REG_USER;
 *      string s_ret_one = "";
 *      getData(&s, &s_pattern, &s_ret_one);
 * @endcode
 * @param [in] msg Строка
 * @param [in] pattern Паттерн
 * @param [out] ret_one Информация с первого нахождения в строке
 */
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

/**
 * @brief Получение информации из строки
 * @code
 *      string s = "user:[SavaLione]";
 *      string s_pattern = BR::REG_USER;
 *      string s_ret_one = "", s_ret_two = "";
 *      getData(&s, &s_pattern, &s_ret_one, &s_ret_two);
 * @endcode
 * @param [in] msg Строка
 * @param [in] pattern Паттерн
 * @param [out] ret_one Информация с первого нахождения в строке
 * @param [out] ret_two Информация с второго нахождения в строке
 */
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
/** @} */