#include "Client.h"

#define MEM_FN(x) boost::bind(&Client::x, shared_from_this())
#define MEM_FN1(x,y) boost::bind(&Client::x, shared_from_this(),y)
#define MEM_FN2(x,y,z) boost::bind(&Client::x, shared_from_this(),y,z)
void Client::start(boost::asio::ip::tcp::endpoint ep)
{
	socket.async_connect(ep, MEM_FN1(OnConnect, _1));
}

typedef boost::system::error_code error_code;
typedef boost::shared_ptr<Client> ptr;

bool Client::IsStarted() { return started; }

static ptr Client::start(boost::asio::io_service *service, boost::asio::ip::tcp::endpoint ep, const std::string & message)
{
	ptr new_(new Client(service, message));
	new_->start(ep);
	return new_;
}

void Client::Stop()
{
	if (!started) return;
	started = false;
	socket.close();
}

void Client::Read()
{
	async_read(socket, buffer(readBuffer), MEM_FN2(ReadComplete, _1, _2), MEM_FN2(OnRead, _1, _2));
}

void Client::Send(const std::string & msg)
{
	if (!started()) return;
	std::copy(msg.begin(), msg.end(), sendBuffer);
	socket.async_write_some(buffer(sendBuffer, msg.size()), MEM_FN2(OnSend, _1, _2));
}

size_t Client::ReadComplete(const error_code & err, size_t bytes)
{
	if (err) return 0;
	bool found = std::find(readBuffer, readBuffer + bytes, '\n') < readBuffer + bytes;
	// we read one-by-one until we get to enter, no buffering
	return found ? 0 : 1;
}

void Client::OnConnect(const error_code & err)
{
	std::cout << "connected" << std::endl;
	if (!err) Send(message + "\n");
	else Stop();
}

void Client::OnRead(const error_code & err, size_t bytes)
{
	if (!err)
	{
		std::string copy(readBuffer, bytes - 1);
		std::cout << "server echoed our " << message << ": " << (copy == message ? "OK" : "FAIL") << std::endl;
	}
	Stop();
}

void Client::OnSend(const error_code & err, size_t bytes)
{
	std::cout << "sended" << std::endl;
	Read();
}