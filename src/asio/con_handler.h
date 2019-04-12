#ifndef CON_HANDLER_H
#define CON_HANDLER_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

class con_handler : public boost::enable_shared_from_this<con_handler>
{
private:
	boost::asio::ip::tcp::socket sock;
	std::string message="Hello From Server!";
	enum { max_length = 1024 };
	char data[max_length];

public:
	typedef boost::shared_ptr<con_handler> pointer;
	con_handler(boost::asio::io_service& io_service) : sock(io_service)
	{
	}

	static pointer create(boost::asio::io_service& io_service)
	{
		return pointer(new con_handler(io_service));
	}

	boost::asio::ip::tcp::socket& socket()
	{
		return sock;
	}

	void start()
	{
		sock.async_read_some(boost::asio::buffer(data, max_length), boost::bind(&con_handler::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
		sock.async_write_some(boost::asio::buffer(message, max_length), boost::bind(&con_handler::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}

	void handle_read(const boost::system::error_code& err, size_t bytes_transferred)
	{
		if (!err) 
		{
			std::cout << data << std::endl;
		} else {
			std::cerr << "err (recv): " << err.message() << std::endl;
			sock.close();
		}
	}

	void handle_write(const boost::system::error_code& err, size_t bytes_transferred)
	{
		if (!err)
		{
			std::cout << "Server sent Hello message!"<< std::endl;
		} else {
			std::cerr << "err (recv): " << err.message() << std::endl;
			sock.close();
		}
	}
};

#endif // CON_HANDLER_H