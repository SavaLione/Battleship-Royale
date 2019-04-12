#include <string>

#include <boost/asio.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

using namespace boost::asio;
using ip::tcp;

int main()
{
    boost::asio::io_service io_service;
    tcp::socket socket(io_service);

    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));

    const std::string msg = "[Message from Client]\n";
    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(msg), error);

    if (!error)
    {
        spdlog::info("Client sent hello message!");
    }
    else
    {
        spdlog::error("Send failed: {}", error.message());
    }

    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);

    if (error && error != boost::asio::error::eof)
    {
        spdlog::error("Receive failed: {}", error.message());
    }
    else
    {
        const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
        spdlog::info("Data from server:");
        spdlog::info(data);
        spdlog::info("End data from server");
    }
    return 0;
}
