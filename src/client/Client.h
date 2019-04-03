#pragma once

#include <iostream>
#include <string>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/chrono.hpp>

#define MEM_FN(x) boost::bind(&Client::x, shared_from_this())
#define MEM_FN1(x,y) boost::bind(&Client::x, shared_from_this(),y)
#define MEM_FN2(x,y,z) boost::bind(&Client::x, shared_from_this(),y,z)
class Client : public boost::enable_shared_from_this<Client>, boost::asio::noncopyable
{
	Client(boost::asio::io_service *service, const std::string & message) : started(true), message(message)
	{
		socket(*service);
	}

	void start(boost::asio::ip::tcp::endpoint ep);

public:
	typedef boost::system::error_code error_code;
	typedef boost::shared_ptr<Client> ptr;

	bool IsStarted();

	static ptr start(boost::asio::io_service *service, boost::asio::ip::tcp::endpoint ep, const std::string & message);
	void Stop();
	void Read();
	void Send(const std::string & msg);
	size_t ReadComplete(const error_code & err, size_t bytes);

private:
	boost::asio::ip::tcp::socket socket;
	enum { max_msg = 1024 };
	char readBuffer[max_msg];
	char sendBuffer[max_msg];
	bool started;
	std::string message;

	void OnConnect(const error_code & err);
	void OnRead(const error_code & err, size_t bytes);
	void OnSend(const error_code & err, size_t bytes);
};