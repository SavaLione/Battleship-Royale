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
        getData(request, BR::REGEX::USER, param_one);
        if (mdb.checkPlayer(param_one))
        {
            ret = BR::REGEX::ANSWER::ANSWER_TRUE;
        }
        else
        {
            ret = BR::REGEX::ANSWER::ANSWER_FALSE;
        }
        break;
    }
    case USER_PASS_CHECK:
    {
        std::string user = "", pass = "", sha2 = "";
        getData(request, BR::REGEX::USER_PASS, user, pass);
        mdb.getPassword(user, sha2);
        if (pass == sha2)
        {
            if (mdbUid.ifFoundName(user))
            {
                // UID найден
            }
            else
            {
                // UID не найден
                mdbUid.setUid(user);
            }
            ret = "UID:[";
            ret += mdbUid.getUid(user);
            ret += "] ";
            
        }
        else
        {
            ret = BR::REGEX::ANSWER::ANSWER_FALSE;
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
        getData(request, BR::REGEX::USER_CREATE, param_one, param_two);
        if (mdb.checkPlayer(param_one))
        {
            ret = BR::REGEX::ANSWER::ERROR_USER_ALREADY_EXIST;
        }
        else
        {
            mdb.createPlayer(param_one, param_two);
            ret = BR::REGEX::ANSWER::SUCCESSFUL_USER_CREATED;
        }
        break;
    }
    case TEST_WITHOUT_DB_CONNECTION:
    {
        ret = "test_without_db_from_server";
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
    if (check_pattern(request, BR::REGEX::USER))
    {
        return USER_CHECK;
    }
    else if (check_pattern(request, BR::REGEX::USER_PASS))
    {
        return USER_PASS_CHECK;
    }
    else if (check_pattern(request, BR::REGEX::UID))
    {
        return USER_UID;
    }
    else if (check_pattern(request, BR::REGEX::USER_CREATE))
    {
        return USER_CREATE;
    }
    else if(request == "test_without_db")
    {
        return TEST_WITHOUT_DB_CONNECTION;
    }
    else
    {
        return REQ_ERROR;
    }
    return REQ_ERROR;
}
/** @} */