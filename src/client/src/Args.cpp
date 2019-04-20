/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 21 Apr 2019
*/
/**
 * @defgroup args_h Args.h
 * @ingroup client
 * @{
 */
#include "Args.h"

#include <cxxopts.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include "BattleshipRoyale.h"
#include "Test.h"

void arg(int argc, char *argv[], int& LOG_LEVEL, int& PORT, std::string& s_ip, std::string& s_test)
{
	/*
		Парсер аргументов к программе
			h	help	Помощь
			v	version	Версия программы
			l	log		Логирование. Возможно стоит убрать
			lo	loop	Тестирование на колличество подключений в секунду
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
			("l,log", "Log level. 0 - debug, 1 - info (default), 2 - warn, 3 - error, 4 - critical, 5 - off.", cxxopts::value<int>(LOG_LEVEL))
			("L,LogFile", "Log to file (default on)")
			("loop", "Loop test connections with out log")
			("p,port", "Port", cxxopts::value<int>(PORT))
            ("i,ip", "IP", cxxopts::value<std::string>(s_ip))
            ("m,msg", "message to server", cxxopts::value<std::string>(s_test));

		auto result = options.parse(argc, argv);

		if (result.count("help"))
		{
			spdlog::info(options.help({ "", "Group" }));
			exit(0);
		}

		if (result.count("version"))
		{
			spdlog::info("client version: {}", BR::VERSION::CLIENT::VERSION);
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
			spdlog::info("Log to console.");
		}
		else
		{
			auto file_logger = spdlog::basic_logger_mt("BR", "Battleship-Royale.log");
    		spdlog::set_default_logger(file_logger);
		}
		

		if (result.count("loop"))
		{
			loopconn(PORT, s_ip);
			exit(0);
		}
	}
	catch (const cxxopts::OptionException& e)
	{
		spdlog::warn(e.what());
		exit(1);
	}
}

/** @} */