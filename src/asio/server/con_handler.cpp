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
        //std::cout << data << std::endl;
        spdlog::info(data);
    }
    else
    {
        //std::cerr << "err (recv): " << err.message() << std::endl;
        spdlog::error("err (recv):  {}", err.message());
        sock.close();
    }
}

void con_handler::handle_write(const boost::system::error_code &err, size_t bytes_transferred)
{
    if (!err)
    {
        //std::cout << "Server sent Hello message!" << std::endl;
        spdlog::info("Server sent Hello message!");
    }
    else
    {
        //std::cerr << "err (recv): " << err.message() << std::endl;
        spdlog::error("err (recv):  {}", err.message());
        sock.close();
    }
}

con_handler::~con_handler()
{
}