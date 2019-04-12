#include <string>

#include <boost/asio.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <cxxopts.hpp>

#include "BattleshipRoyale.h"

using namespace boost::asio;
using ip::tcp;

int main(int argc, char *argv[])
{
	#ifdef _OPENMP
	/*
		Выводим текст в консоль каждым потоком
		Нужно для проверки количества задействованных потоков
	*/
	std::string s_omp_parallel_cores_test = "";
	#pragma omp parallel
	{
		s_omp_parallel_cores_test += "[CORE] ";
	}
	spdlog::info("Cores: {}", s_omp_parallel_cores_test);

	/*
		Вывод данных о возможности использования OpenMP 
	*/
	spdlog::info("Compiled by an OpenMP-compliant implementation.");
	#else
	spdlog::warn("Compiled WITHOUT an OpenMP-compliant implementation.");
	#endif

	spdlog::info("Welcome to Battleship Royale Console Client!");
	/*
		Arg opt
	*/
	bool HIDE_LOG = false;
	int PORT = BR::SERVER_PORT;
    std::string s_ip = BR::SERVER_IP;
    std::string s_test = "1";
	/*
		Парсер аргументов к программе
			h	help	Помощь
			v	version	Версия программы
			l	log		Логирование. Возможно стоит убрать
			p	port	Порт сервера
            i   ip      Адрес сервера
            t   test    Тест
	*/
	try
	{
		cxxopts::Options options("BattleshipRoyaleClient", " - Battleship Royale Console Client");

		options.add_options()
			("h,help", "Help")
			("v,version", "Version")
			("l,log", "Log", cxxopts::value<bool>(HIDE_LOG))
			("p,port", "Port", cxxopts::value<int>(PORT))
            ("i,ip", "IP", cxxopts::value<std::string>(s_ip))
            ("t,test", "Test", cxxopts::value<std::string>(s_test));

		auto result = options.parse(argc, argv);

		if (result.count("help"))
		{
			spdlog::info(options.help({ "", "Group" }));
			exit(0);
		}

		if (result.count("version"))
		{
			spdlog::info(BR::VERSION_CLIENT);
			exit(0);
		}
	}
	catch (const cxxopts::OptionException& e)
	{
		spdlog::warn(e.what());
		exit(1);
	}

    spdlog::info("IP: {}", s_ip);
    spdlog::info("PORT: {}", PORT);

    boost::asio::io_service io_service;
    tcp::socket socket(io_service);

    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string(s_ip), PORT));

    std::string msg = "[Message from Client] ";
    msg += s_test;
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
        spdlog::info("-----------------");
        spdlog::info("Data from server:");
        spdlog::info(data);
    }
    
    return 0;
}
