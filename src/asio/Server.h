#ifndef SERVER_H
#define SERVER_H

#include "con_handler.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

class Server {
private:
	boost::asio::ip::tcp::acceptor acceptor_;
	void start_accept();

public:
	Server(boost::asio::io_service& io_service): acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1234))
	{ 
		start_accept();
	}

	void handle_accept(con_handler::pointer connection, const boost::system::error_code& err);

	/* des */
	~Server();
};

#endif // SERVER_H