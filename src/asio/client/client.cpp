#include <iostream>
#include <boost/asio.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;
using std::string;

int main()
{
    boost::asio::io_service io_service;
    tcp::socket socket(io_service);

    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));

    const string msg = "[Message from Client]\n";
    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(msg), error);

    if (!error)
    {
        //cout << "Client sent hello message!" << endl;
        spdlog::info("Client sent hello message!");
    }
    else
    {
        //cout << "send failed: " << error.message() << endl;
        spdlog::error("Send failed: {}", error.message());
    }

    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);

    if (error && error != boost::asio::error::eof)
    {
        //cout << "receive failed: " << error.message() << endl;
        spdlog::error("Receive failed: {}", error.message());
    }
    else
    {
        const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
        //cout << "\n\nData from server:\n" << endl;
        //cout << data << endl;
        //cout << "End data from server\n" << endl;
        spdlog::info("Data from server:");
        spdlog::info(data);
        spdlog::info("End data from server");
    }
    return 0;
}
