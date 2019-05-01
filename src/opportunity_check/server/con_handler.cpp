#include "con_handler.h"

#include <boost/bind.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

boost::asio::ip::tcp::socket& con_handler::socket()
{
    return sock;
}

void con_handler::start()
{
    sock.async_read_some(boost::asio::buffer(data, max_length), boost::bind(&con_handler::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    sock.async_write_some(boost::asio::buffer(message, max_length), boost::bind(&con_handler::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void con_handler::handle_read(const boost::system::error_code &err, size_t bytes_transferred)
{
    if (!err)
    {
        spdlog::info(data);
    }
    else
    {
        spdlog::error("err (recv):  {}", err.message());
        sock.close();
    }
}

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

con_handler::~con_handler()
{
}