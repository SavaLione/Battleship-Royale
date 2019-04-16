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

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include "BattleshipRoyale.h"

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
        data_check = data;
        answ = prc.response(data_check);
    }
    else
    {
        spdlog::error("err (recv):  {}", err.message());
        sock.close();
    }
    sock.async_write_some(boost::asio::buffer(answ, max_length), boost::bind(&con_handler::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
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
    answ = "";
}

/**
 * @brief Деструктор класса
 */
con_handler::~con_handler()
{
}
/** @} */