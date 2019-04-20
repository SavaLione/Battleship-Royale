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

void test(int const& PORT, std::string const& s_ip);

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
			spdlog::info("client version: {}", BR::VERSION::CLIENT::VERSION);
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

	// Client ct;
	// ct.setPort(PORT);
	// ct.setIp(s_ip);
	// ct.connect();
	// ct.send(s_test);
	// spdlog::info(ct.receive());

	test(PORT, s_ip);

    return 0;
}

/**
 * |user_check true|user_check false|user pass true|user pass false|
 * [ ][ ][ ][ ]
 */
void test(int const& PORT, std::string const& s_ip)
{
	spdlog::info("|user_check true|user_check false|user pass true|user pass false|");
	spdlog::info("|---------------|----------------|--------------|---------------|");
	int connections = 0;
	while(true)
	{
		bool bt[] = { true, true , true, true};
		connections++;
		{
			std::string msg = "user_check:[SavaLione]";
			Client ct;
			ct.setPort(PORT);
			ct.setIp(s_ip);
			ct.connect();
			ct.send(msg);
			if(ct.receive() != "answer:[true]")
			{
				bt[0] = false;
			}
		}

		{
			std::string msg = "user_check:[NOTNOTNOT]";
			Client ct;
			ct.setPort(PORT);
			ct.setIp(s_ip);
			ct.connect();
			ct.send(msg);
			if(ct.receive() != "answer:[false]")
			{
				bt[1] = false;
			}
		}

		{
			std::string msg = "user:[OwO] pass:[OwO]";
			Client ct;
			ct.setPort(PORT);
			ct.setIp(s_ip);
			ct.connect();
			ct.send(msg);
			if(ct.receive() != "UID:[OWWO111OwO123OwO111OwO]")
			{
				bt[2] = false;
			}
		}

		{
			std::string msg = "user:[Hewwwoo] pass:[Hiii]";
			Client ct;
			ct.setPort(PORT);
			ct.setIp(s_ip);
			ct.connect();
			ct.send(msg);
			if(ct.receive() == "answer:[true]")
			{
				bt[3] = false;
			}
		}

		{
			std::string s = "";
			if(bt[0])
			{
				s += "[ ]";
			}
			else
			{
				s += "[X]";
			}

			if(bt[1])
			{
				s += "[ ]";
			}
			else
			{
				s += "[X]";
			}

			if(bt[2])
			{
				s += "[ ]";
			}
			else
			{
				s += "[X]";
			}

			if(bt[3])
			{
				s += "[ ]";
			}
			else
			{
				s += "[X]";
			}
			s += " ";
			s += connections;
			
			spdlog::info(s);
		}
	}
}
/** @} */