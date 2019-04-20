/**
 * @file
 * @deprecated
 */
#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace boost;
using namespace asio;
using namespace ip;

io_service service;

class ServerLink : public enable_shared_from_this<ServerLink>, noncopyable
{
public:
	typedef shared_ptr<ServerLink> ptr;

	bool IsConnected() { return connected; }
	bool IsSending() { return sending; }
	bool IsReading() { return reading; }
	std::string Message() { return message; }

	static ptr Start(ip::tcp::endpoint ep)
	{
		ptr link(new ServerLink());
		link->Connect(ep);
		return link;
	}

	void Disconnect()
	{
		if (!connected)return;
		connected = false;
		sock.close();
	}

	void Send(const std::string & msg)
	{
		if (!connected || sending)return;

		sending = true;
		std::copy(msg.begin(), msg.end(), sendBuffer);
		sock.async_write_some(buffer(sendBuffer, msg.size()), boost::bind(&ServerLink::OnSend, shared_from_this(), _1, _2));
	}

	size_t ReadComplete(const system::error_code & error, size_t bytes)
	{
		if (error) return 0;
		bool found = std::find(readBuffer, readBuffer + bytes, '\n') < readBuffer + bytes;
		// we read one-by-one until we get to enter, no buffering
		return found ? 0 : 1;
	}

private:
	tcp::socket sock;
	char readBuffer[1024];
	char sendBuffer[1024];
	bool connected, sending, reading;
	std::string message;

	ServerLink() : sock(service), connected(false) { }

	void Connect(tcp::endpoint ep)
	{
		sock.connect(ep);
		connected = true;
	}

	void Read()
	{
		if (!connected || reading)return;

		reading = true;
		async_read(sock, buffer(readBuffer),
			boost::bind(&ServerLink::ReadComplete, shared_from_this(), _1, _2), boost::bind(&ServerLink::OnRead, shared_from_this(), _1, _2));
	}

	void OnConnect(const system::error_code & error)
	{
		connected = true;
		Read();
	}

	void OnRead(const system::error_code & error, size_t bytes)
	{
		reading = false;
		if (!error)
		{
			std::string msg(readBuffer, bytes - 1);
			message = msg;
		}
		if (connected)
			Read();
	}

	void OnSend(const system::error_code & error, size_t bytes)
	{
		sending = false;
	}
};