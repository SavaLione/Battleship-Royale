#ifndef CON_HANDLER_H
#define CON_HANDLER_H

#include <boost/asio.hpp>
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

	boost::asio::ip::tcp::socket& socket();

	void start();

	void handle_read(const boost::system::error_code& err, size_t bytes_transferred);

	void handle_write(const boost::system::error_code& err, size_t bytes_transferred);

	/* des */
	~con_handler();
};

#endif // CON_HANDLER_H