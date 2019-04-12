#include "Server.h"

Server::Server(boost::asio::io_service& io_service): acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1234))
{ 
	start_accept();
}

Server::~Server()
{

}

void Server::start_accept()
{
	// creates a socket
	con_handler::pointer connection = con_handler::create(acceptor_.get_io_service());
	// initiates an asynchronous accept operation 
	// to wait for a new connection. 
	acceptor_.async_accept(connection->socket(), boost::bind(&Server::handle_accept, this, connection, boost::asio::placeholders::error));
}

void Server::handle_accept(con_handler::pointer connection, const boost::system::error_code& err)
{
	if (!err)
	{
		connection->start();
	}
	start_accept();
}