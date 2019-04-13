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
boost::asio::ip::tcp::socket& con_handler::socket()
{
    return sock;
}

/**
 * @brief Запуск handler
 */
void con_handler::start()
{
    sock.async_read_some(boost::asio::buffer(data, max_length), boost::bind(&con_handler::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    sock.async_write_some(boost::asio::buffer(message, max_length), boost::bind(&con_handler::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
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
        spdlog::info("--------------------------");
        spdlog::info(data);

        std::string s_data = data;

        std::string s_param_one = "";
        std::string s_param_two = "";

        std::string s_pattern_reg_user = BR::REG_USER;
        std::string s_pattern_reg_user_pass = BR::REG_USER_PASS;
        std::string s_pattern_reg_uid = BR::REG_UID;

        if(check_pattern(&s_data, &s_pattern_reg_user))
        {
            getData(&s_data, &s_pattern_reg_user, &s_param_one);
            //spdlog::error("{} {}", s_data, s_param_one);
        }

        if(check_pattern(&s_data, &s_pattern_reg_user_pass))
        {
            getData(&s_data, &s_pattern_reg_user_pass, &s_param_one, &s_param_two);
            //spdlog::error("{} {} {}", s_data, s_param_one, s_param_two);
        }

        if(check_pattern(&s_data, &s_pattern_reg_uid))
        {
            getData(&s_data, &s_pattern_reg_uid, &s_param_one, &s_param_two);
            //spdlog::error("{} {} {}", s_data, s_param_one, s_param_two);
        }
        memset(data, 0, sizeof data);
    }
    else
    {
        spdlog::error("err (recv):  {}", err.message());
        sock.close();
    }
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
        spdlog::info("Server sent Hello message!");
    }
    else
    {
        spdlog::error("err (recv):  {}", err.message());
        sock.close();
    }
}

/**
 * @brief Деструктор класса
 */
con_handler::~con_handler()
{
}
/** @} */