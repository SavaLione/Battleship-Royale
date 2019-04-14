/**
 * @file
 * @brief handler
 * @author SavaLione
 * @date 14 Apr 2019
 */
/**
 * @defgroup con_handler_cpp con_handler.cpp
 * @ingroup server
 * @{
 */
#include "con_handler.h"

#include <string>

#include <boost/bind.hpp>
#include <boost/regex.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include "BattleshipRoyale.h"
#include "Regex.h"

/**
 * @brief Сокет
 * @return Сокет
 */
boost::asio::ip::tcp::socket &con_handler::socket()
{
    return sock;
}

/**
 * @brief Запуск handler
 */
void con_handler::start()
{
    sock.async_read_some(boost::asio::buffer(data, max_length), boost::bind(&con_handler::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

/**
 * @brief Чтение сообщения от клиента
 * @param [out] err ошибка
 * @param [in] bytes_transferred 
 */
void con_handler::handle_read(const boost::system::error_code &err, size_t bytes_transferred)
{
    if (!err)
    {
        *data_check = data;
        if(processing_user_check(data_check))
        {

        }
        else if(processing_user_pass_check(data_check))
        {

        }
        else
        {

        }
    }
    else
    {
        spdlog::error("err (recv):  {}", err.message());
        sock.close();
    }
    sock.async_write_some(boost::asio::buffer(*answ, max_length), boost::bind(&con_handler::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

/**
 * @brief обработка запроса. Поиск имени пользователя
 * @param [in] request запрос
 * @return true - запрос подходит(обработан), false - запрос не подходит(не обработан)
 */
bool con_handler::processing_user_check(std::string *request)
{
    *s_param_one = "";
    *s_pattern_reg = BR::REG_USER;

    if (check_pattern(request, s_pattern_reg))
    {
        getData(request, s_pattern_reg, s_param_one);

        if (mdb->checkPlayer(s_param_one))
        {
            *answ = BR::ANSWER_TRUE;
        }
        else
        {
            *answ = BR::ANSWER_FALSE;
        }

        return true;
    }
    return false;
}

/**
 * @brief обработка запроса. Поиск имени и пароля
 * @param [in] request запрос
 * @return true - имя и пароль верны, false - имя и пароль не верны.
 */
bool con_handler::processing_user_pass_check(std::string *request)
{
    *s_param_one = "";
    *s_param_two = "";
    *s_pattern_reg = BR::REG_USER_PASS;

    if (check_pattern(request, s_pattern_reg))
    {
        getData(request, s_pattern_reg, s_param_one, s_param_two);
        //void getPassword(std::string *name, std::string *sha2_ret);
        mdb->getPassword(s_param_one, s_sha2);
        if(*s_param_two == *s_sha2)
        {
            *answ = BR::ANSWER_TRUE;
        }
        else
        {
            *answ = BR::ANSWER_FALSE;
        }

        return true;
    }
    return false;
}

/**
 * @brief Отправка сообщения клиенту
 * @param [out] err ошибка
 * @param [in] bytes_transferred 
 */
void con_handler::handle_write(const boost::system::error_code &err, size_t bytes_transferred)
{
    if (!err)
    {

    }
    else
    {
        spdlog::error("err (recv):  {}", err.message());
        sock.close();
    }
    memset(data, 0, max_length);
    //*data = "";
    *answ = "";
	*s_param_one = "";
	*s_param_two = "";
	*s_pattern_reg = "";
	*s_sha2 = "";
}

/**
 * @brief Деструктор класса
 */
con_handler::~con_handler()
{
    sock.close();
    delete[] data;
    delete answ;
    delete mdb;
    delete data_check;
    delete s_param_one;
    delete s_param_two;
    delete s_pattern_reg;
    delete s_sha2;
}
/** @} */