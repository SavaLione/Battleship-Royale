/**
 * @file
 * @brief Сервер
 * @author SavaLione
 * @date 13 Apr 2019
*/
/**
 * @defgroup battleshiproyalecpp BattleShiproyale.cpp
 * @ingroup server
 * @{
 */
#include <iostream>
#include <string>
#include <future>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <cxxopts.hpp>

#include "BattleshipRoyale.h"
#include "Check.h"
#include "MiniDB.h"
#include "MemDBuid.h"
#include "Console.h"

#include "Server.h"

using namespace std;

/**
 * @brief Точка входа в программу
 * @param [in] argc количество аргументов для парсера
 * @param [in] argv[] аргументы для парсера
 * @return 0 - успешное выполнение программы, 1 - выполнение программы с ошибкой.
 */
int main(int argc, char *argv[])
{
	/*
		Arg opt
	*/
	int PORT = BR::CONNECT::PORT;

	/**
	 * 0 - debug
	 * 1 - info
	 * 2 - warn
	 * 3 - error
	 * 4 - critical
	 * 5 - off
	 */
	int LOG_LEVEL = 1;

	/*
		Парсер аргументов к программе
			h	help	Помощь
			v	version	Версия программы
			l	log		Уровень логирования. Стандарт - info.
			p	port	Порт сервера
	*/
	try
	{
		cxxopts::Options options("BattleshipRoyaleServer", " - Battleship Royale Server");

		options.add_options()
			("h,help", "Help")
			("v,version", "Version")
			("l,log", "Log level. 0 - debug, 1 - info (default), 2 - warn, 3 - error, 4 - critical, 5 - off.", cxxopts::value<int>(LOG_LEVEL))
			("L,LogFile", "Log to file")
			("p,port", "Port", cxxopts::value<int>(PORT));

		auto result = options.parse(argc, argv);

		if (result.count("help"))
		{
			spdlog::info(options.help({"", "Group"}));
			exit(0);
		}

		if (result.count("version"))
		{
			spdlog::info("server version: {}.{}.{}", BR::VERSION::SERVER::MAJOR, BR::VERSION::SERVER::MINOR, BR::VERSION::SERVER::PATCH);
			spdlog::info("sqlite3 version: {} ({})", SQLITE_VERSION, SQLITE_VERSION_NUMBER);
			spdlog::info("cxxopts version: {}", ((CXXOPTS__VERSION_MAJOR * 10000) + (CXXOPTS__VERSION_MINOR * 100) + (SPDLOG_VER_PATCH)));
			spdlog::info("spdlog version: {}", SPDLOG_VERSION);
			exit(0);
		}

		if(LOG_LEVEL == 0)
		{
			spdlog::set_level(spdlog::level::debug);
		}
		else if (LOG_LEVEL == 1)
		{
			spdlog::set_level(spdlog::level::info);
		}
		else if (LOG_LEVEL == 2)
		{
			spdlog::set_level(spdlog::level::warn);
		}
		else if (LOG_LEVEL == 3)
		{
			spdlog::set_level(spdlog::level::err);
		}
		else if (LOG_LEVEL == 4)
		{
			spdlog::set_level(spdlog::level::critical);
		}
		else if (LOG_LEVEL == 5)
		{
			spdlog::set_level(spdlog::level::off);
		}
		else
		{
			spdlog::warn("Log level: {}. Not found!", LOG_LEVEL);
		}

		if (result.count("LogFile"))
		{
			auto file_logger = spdlog::basic_logger_mt("BR", "Battleship-Royale.log");
    		spdlog::set_default_logger(file_logger);
		}
	}
	catch (const cxxopts::OptionException &e)
	{
		spdlog::warn(e.what());
		exit(1);
	}

	{
		spdlog::info("Check OpenMP.");
		int check = BR::CHECK::openmp();
		if (check >= 0)
		{
			/*
				Вывод данных о возможности использования OpenMP 
			*/
			spdlog::info("Compiled by an OpenMP-compliant implementation.");
			spdlog::info("Cores: {}", check);
		}
		else
		{
			spdlog::warn("Compiled WITHOUT an OpenMP-compliant implementation.");
		}
	}

	spdlog::info("Welcome to Battleship Royale Server!");

	/*
		DB initialization
	*/
	MiniDB mdb;
	mdb.setTable();

	/*
		MemDBuid initialization
	*/
	MemDBuid mdbUid;
	mdbUid.create();

	/*
		Start server
	*/
	spdlog::info("Start Battleship Royale Server!");
	spdlog::info("Port: {}", PORT);

	/*
		Console
	*/
	std::future<void> result(std::async(BR::CONSOLE::start));

	try
	{
		boost::asio::io_service io_service;
		Server server(io_service, &PORT);
		io_service.run();
	}
	catch (std::exception &e)
	{
		spdlog::error("Error create Server!");
		spdlog::error(e.what());
	}

	return 0;
}
/** @} */