/**
 * @file
 * @brief Клиент
 * @author SavaLione
 * @date 14 Apr 2019
*/
/**
 * @defgroup battleshiproyale_cpp BattleShiproyale.cpp
 * @ingroup client
 * @{
 */
#include <string>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <cxxopts.hpp>

#include "BattleshipRoyale.h"
#include "Client.h"

#include "Test.h"

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
	bool HIDE_LOG = false;
	int PORT = BR::CONNECT::PORT;
    std::string s_ip = BR::CONNECT::IP;
    std::string s_test = "";
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
			("l,log", "Log", cxxopts::value<bool>(HIDE_LOG))
			("f,loop", "Loop test connections with out log")
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
			spdlog::info("client version: {}", BR::VERSION::CLIENT::VERSION);
			exit(0);
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

	spdlog::info("Welcome to Battleship Royale Console Client!");

    spdlog::info("IP: {}", s_ip);
    spdlog::info("PORT: {}", PORT);

	Client ct;
	ct.setPort(PORT);
	ct.setIp(s_ip);
	ct.connect();
	ct.send(s_test);
	spdlog::info(ct.receive());

    return 0;
}
/** @} */