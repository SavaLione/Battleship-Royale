/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 20 Apr 2019
*/
/**
 * @defgroup client_h Client.h
 * @ingroup client
 * @{
 */
#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <boost/asio.hpp>
#include <BattleshipRoyale.h>

class Client
{
private:
    int port;
    std::string ip;
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket;
    boost::system::error_code error;
    boost::asio::streambuf receive_buffer;

public:
    Client();
    ~Client();
    void setPort(int const& port);
    void setIp(std::string const& ip);
    void connect();
    void send(std::string const& msg);
    std::string receive();
};

#endif // CLIENT_H
/** @} */