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
    sock.async_read_some(boost::asio::buffer(data, max_length), boost::bind(&con_handler::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    //sock.async_write_some(boost::asio::buffer(*message, max_length), boost::bind(&con_handler::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

    //char test[max_length];

    auto self(shared_from_this());
    boost::asio::async_write(
        sock,
        boost::asio::buffer(
            *message,
            max_length
            ),
            [this, self](
                boost::system::error_code ec,
                std::size_t length
            )
            {
            if (!ec)
            {
                //do_write(length);
                spdlog::info("SoMe");
            }
            }
    );

    /*
    sock.async_read_some(
        boost::asio::buffer(data, max_length), 
        boost::bind(&con_handler::handle_read, 
                    shared_from_this(), 
                    boost::asio::placeholders::error, 
                    boost::asio::placeholders::bytes_transferred
                    )
        );
    
    sock.async_write_some(
        boost::asio::buffer(*message, max_length),
        boost::bind(&con_handler::handle_write,
                    shared_from_this(),
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred
                    )
        );
    ---
    boost::asio::async_write(
        sock,
        boost::asio::buffer(
            *message,
            max_length
            ),
        boost::bind(
            &con_handler::handle_read, 
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
            )
    );

    auto self(shared_from_this());
    boost::asio::async_write(
        sock,
        boost::asio::buffer(
            *message,
            max_length
            ),
            [this, self](
                boost::system::error_code ec,
                std::size_t length
            )
    );
    ---
    auto self(shared_from_this());
    socket_.async_read_some(
        boost::asio::buffer(data_, max_length),
        [this, self](
            boost::system::error_code ec,
            std::size_t length
            )
        {
          if (!ec)
          {
            do_write(length);
          }
        });
    
    auto self(shared_from_this());
    boost::asio::async_write(
        socket_,
        boost::asio::buffer(
            data_, 
            length
            ),
        [this, self](
            boost::system::error_code ec, 
            std::size_t
            )
        {
          if (!ec)
          {
            do_read();
          }
        });
    */
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
        std::string s_data = data;
        if(processing_user_check(&s_data))
        {
            spdlog::warn("processing_user_check");
            spdlog::warn(s_data);
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

        memset(data, 0, sizeof data);
    }
    else
    {
        spdlog::error("err (recv):  {}", err.message());
        sock.close();
    }
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
            *message = BR::ANSWER_TRUE;
        }
        else
        {
            *message = BR::ANSWER_FALSE;
        }

        delete db;
        ret = true;
        spdlog::warn(*message);
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
    delete message;
}
/** @} */