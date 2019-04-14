/**
 * @file
 * @brief Асинхронный сервер написанный на boost asio
 * @author SavaLione
 * @date 14 Apr 2019
 */
/**
 * @defgroup serverh Server.h
 * @ingroup server
 * @{
 */
#ifndef SERVER_H
#define SERVER_H

#include "con_handler.h"

/**
 * @brief Асинхронный сервер написанный на boost asio
 */
class Server {
private:
	/**
	 * @brief acceptor_
	 */
	boost::asio::ip::tcp::acceptor acceptor_;

	/**
	 * @brief Запуск acceptor_
	 */
	void start_accept();

public:
    /**
     * @brief Конструктор класса
	 * 
	 * С списком инициализации
	 * 
	 * @param [in] io_service сервис
	 * @param [in] i_port порт сервера
     */
	Server(boost::asio::io_service& io_service, int *i_port) : acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), *i_port))
	{
		start_accept();
	}

    /**
     * @brief handle
	 * @param [in] connection указатель на подключение
	 * @param [out] err сервера ссылка на ошибку
     */
	void handle_accept(con_handler::pointer connection, const boost::system::error_code& err);

    /**
     * @brief Деструктор класса
     */
	~Server();
};

#endif // SERVER_H
/** @} */