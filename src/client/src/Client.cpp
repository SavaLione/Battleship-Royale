/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 20 Apr 2019
*/
/**
 * @defgroup client_cpp Client.cpp
 * @ingroup client
 * @{
 */
#include "Client.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

using namespace boost::asio;
using ip::tcp;

Client::Client() : port(BR::CONNECT::PORT), ip(BR::CONNECT::IP), socket(io_service)
{
}

Client::~Client()
{
}

void Client::connect()
{
    try
    {
        this->socket.connect(tcp::endpoint(boost::asio::ip::address::from_string(this->ip), this->port));
    }
    catch(const std::exception& e)
    {
        spdlog::error(e.what());
    }
}

void Client::setPort(int const& port)
{
    this->port = port;
}

void Client::setIp(std::string const& ip)
{
    this->ip = ip;
}

void Client::send(std::string const& msg)
{
    boost::asio::write(this->socket, boost::asio::buffer(msg), this->error);

    if (!(this->error))
    {
        // Client send message
    }
    else
    {
        spdlog::error("Send failed: {}", error.message());
    }
}

std::string Client::receive()
{
    boost::asio::read(this->socket, this->receive_buffer, boost::asio::transfer_all(), this->error);

    if (error && error != boost::asio::error::eof)
    {
        spdlog::error("Receive failed: {}", error.message());
    }
    else
    {
        const char *data = boost::asio::buffer_cast<const char *>(this->receive_buffer.data());
        return data;
    }

    return "ERROR";
}
/** @} */