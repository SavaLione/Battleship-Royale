#ifndef SERVER_H
#define SERVER_H

#include "con_handler.h"

class Server {
private:
	boost::asio::ip::tcp::acceptor acceptor_;
	void start_accept();

public:

	/*
	Server(boost::asio::io_service& io_service) : acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1234))
	{ 
		start_accept();
	}
	*/

	Server(boost::asio::io_service& io_service, int i_port) : acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), i_port))
	{
		start_accept();
	}

	void handle_accept(con_handler::pointer connection, const boost::system::error_code& err);

	/* des */
	~Server();
};

#endif // SERVER_H