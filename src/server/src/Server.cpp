/**
 * @file
 * @brief Асинхронный сервер написанный на boost asio
 * @author SavaLione
 * @date 14 Apr 2019
 */
/**
 * @defgroup servercpp Server.cpp
 * @ingroup server
 * @{
 */
#include "Server.h"

#include <boost/bind.hpp>

/**
 * @brief Запуск acceptor_
 */
void Server::start_accept()
{
	// creates a socket
	con_handler::pointer connection = con_handler::create(acceptor_.get_io_service());
	// initiates an asynchronous accept operation 
	// to wait for a new connection. 
	acceptor_.async_accept(connection->socket(), boost::bind(&Server::handle_accept, this, connection, boost::asio::placeholders::error));
}

/**
 * @brief handle
 * @param [in] connection указатель на подключение
 * @param [out] err сервера ссылка на ошибку
 */
void Server::handle_accept(con_handler::pointer connection, const boost::system::error_code& err)
{
	if (!err)
	{
		connection->start();
	}
	start_accept();
}

/**
 * @brief Деструктор класса
 */
Server::~Server()
{

}

/** @} */