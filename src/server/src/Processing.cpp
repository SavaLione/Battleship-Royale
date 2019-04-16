/**
 * @file
 * @brief Обработка запросов
 * @author SavaLione
 * @date 16 Apr 2019
*/
/**
 * @defgroup processing_cpp Processing.cpp
 * @ingroup server
 * @{
*/
#include "Processing.h"

#include <string>

#include "Regex.h"
#include "BattleshipRoyale.h"

/**
 * @brief Конструктор класса
 */
Processing::Processing()
{
}

/**
 * @brief Деструктор класса
 */
Processing::~Processing()
{
}

/**
 * @brief Запрос
 * @param [in] request строка с запросом
 * @return Ответ
 */
std::string Processing::response(std::string const &request)
{
    std::string ret = "";
    REQ r = getREQ(request);

    switch (r)
    {
    case USER_CHECK:
    {
        std::string param_one = "";
        getData(request, BR::REG_USER, param_one);
        if (mdb.checkPlayer(param_one))
        {
            ret = BR::ANSWER_TRUE;
        }
        else
        {
            ret = BR::ANSWER_FALSE;
        }
        break;
    }
    case USER_PASS_CHECK:
    {
        std::string param_one = "", param_two = "", sha2 = "";
        getData(request, BR::REG_USER_PASS, param_one, param_two);
        mdb.getPassword(param_two, sha2);
        if (param_two == sha2)
        {
            ret = BR::ANSWER_TRUE;
        }
        else
        {
            ret = BR::ANSWER_FALSE;
        }
        break;
    }
    case USER_UID:
    {
        ret = "USER_UID";
        break;
    }
    case USER_CREATE:
    {
        std::string param_one = "", param_two = "";
        getData(request, BR::REG_USER_CREATE, param_one, param_two);
        if (mdb.checkPlayer(param_one))
        {
            ret = BR::ANSWER_ERROR_USER_ALREADY_EXIST;
        }
        else
        {
            mdb.createPlayer(param_one, param_two);
            ret = BR::ANSWER_SUCCESSFUL_USER_CREATED;
        }
        break;
    }
    case REQ_ERROR:
    {
        ret = "REQ_ERROR";
        break;
    }
    default:
        ret = "REQ_ERROR";
        break;
    }

    return ret;
}

Processing::REQ Processing::getREQ(std::string const &request)
{
    if (check_pattern(request, BR::REG_USER))
    {
        return USER_CHECK;
    }
    else if (check_pattern(request, BR::REG_USER_PASS))
    {
        return USER_PASS_CHECK;
    }
    else if (check_pattern(request, BR::REG_UID))
    {
        return USER_UID;
    }
    else if (check_pattern(request, BR::REG_USER_CREATE))
    {
        return USER_CREATE;
    }
    else
    {
        return REQ_ERROR;
    }
    return REQ_ERROR;
}
/** @} */