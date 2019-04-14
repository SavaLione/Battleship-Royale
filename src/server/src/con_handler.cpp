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
#include "DB.h"
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
    spdlog::warn("1 {}", answer);
    spdlog::warn("1 fl {}", fl);
    sock.async_read_some(boost::asio::buffer(data, max_length), boost::bind(&con_handler::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    //sock.async_write_some(boost::asio::buffer(*message, max_length), boost::bind(&con_handler::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    spdlog::warn("2 {}", answer);
    spdlog::warn("2 fl {}", fl);

    //sock.async_write_some(boost::asio::buffer(answer, max_length), boost::bind(&con_handler::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    spdlog::warn("3 {}", answer);
    spdlog::warn("3 fl {}", fl);
}

/**
 * @brief Чтение сообщения от клиента
 * @param [out] err ошибка
 * @param [in] bytes_transferred 
 */
void con_handler::handle_read(const boost::system::error_code &err, size_t bytes_transferred)
{
    spdlog::warn("4 {}", answer);
    spdlog::warn("4 fl {}", fl);
    if (!err)
    {
        std::string s_data = data;
        if(processing_user_check(&s_data))
        {
            spdlog::warn("processing_user_check");
            spdlog::warn(s_data);
            spdlog::error("answer {}", answer);
        }
        else if(processing_user_pass_check(&s_data))
        {
            spdlog::warn("processing_user_pass_check");
            spdlog::warn(s_data);
        }
        else
        {
            spdlog::warn("Nothing");
        }
    }
    else
    {
        spdlog::error("err (recv):  {}", err.message());
        sock.close();
    }
    fl = true;
    spdlog::warn("5 {}", answer);
    spdlog::warn("5 fl {}", fl);
    
    sock.async_write_some(boost::asio::buffer(answer, max_length), boost::bind(&con_handler::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

}

/**
 * @brief обработка запроса. Поиск имени пользователя
 * @param [in] request запрос
 * @return true - запрос подходит(обработан), false - запрос не подходит(не обработан)
 */
bool con_handler::processing_user_check(std::string *request)
{
    std::string s_param_one = "";
    std::string s_pattern_reg_user = BR::REG_USER;
    bool ret = false;

    if (check_pattern(request, &s_pattern_reg_user))
    {
        getData(request, &s_pattern_reg_user, &s_param_one);
        DB *db = new DB;

        if ((*db).db_check_player(&s_param_one))
        {
            std::string s = BR::ANSWER_TRUE;
            strncpy(answer, s.c_str(), max_length);
        }
        else
        {
            std::string s = BR::ANSWER_FALSE;
            strncpy(answer, s.c_str(), max_length);
        }

        delete db;
        ret = true;
    }
    return ret;
}

/**
 * @brief обработка запроса. Поиск имени и пароля
 * @param [in] request запрос
 * @return true - имя и пароль верны, false - имя и пароль не верны.
 */
bool con_handler::processing_user_pass_check(std::string *request)
{
    std::string s_param_one = "";
    std::string s_param_two = "";
    std::string s_pattern_reg_user = BR::REG_USER_PASS;
    bool ret = false;

    if (check_pattern(request, &s_pattern_reg_user))
    {
        getData(request, &s_pattern_reg_user, &s_param_one, &s_param_two);
        DB *db = new DB;

        login l_user;
        l_user.s_name = s_param_one;
        l_user.s_password = s_param_two;

        if((*db).db_check_pass(&l_user))
        {
            spdlog::warn("PASS OK");
        }

        delete db;
        ret = true;
    }
    return ret;
}

/**
 * @brief Отправка сообщения клиенту
 * @param [out] err ошибка
 * @param [in] bytes_transferred 
 */
void con_handler::handle_write(const boost::system::error_code &err, size_t bytes_transferred)
{
    spdlog::warn("6 {}", answer);
    spdlog::warn("6 fl {}", fl);
    while(!fl)
    {

    }
    spdlog::warn("7 {}", answer);
    spdlog::warn("7 fl {}", fl);

    if (!err)
    {

    }
    else
    {
        spdlog::error("err (recv):  {}", err.message());
        sock.close();
    }
    spdlog::warn("8 {}", answer);
    memset(data, 0, max_length);
    memset(answer, 0, max_length);
    spdlog::warn("9 {}", answer);
}

/**
 * @brief Деструктор класса
 */
con_handler::~con_handler()
{
    delete[] answer;
}
/** @} */