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

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <cxxopts.hpp>

#include "BattleshipRoyale.h"
#include "Regex.h"
#include "MiniDB.h"

#include "Server.h"

#include "rand_sse.h"

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
	bool HIDE_LOG = false;
	int PORT = BR::SERVER_PORT;

	/*
		Парсер аргументов к программе
			h	help	Помощь
			v	version	Версия программы
			l	log		Логирование. Возможно стоит убрать
			p	port	Порт сервера
	*/
	try
	{
		cxxopts::Options options("BattleshipRoyaleServer", " - Battleship Royale Server");

		options.add_options()
			("h,help", "Help")
			("v,version", "Version")
			("l,log", "Log", cxxopts::value<bool>(HIDE_LOG))
			("p,port", "Port", cxxopts::value<int>(PORT));

		auto result = options.parse(argc, argv);

		if (result.count("help"))
		{
			spdlog::info(options.help({ "", "Group" }));
			exit(0);
		}

		if (result.count("version"))
		{
			spdlog::info("server version: {}", BR::SERVER_VERSION);
			spdlog::info("client version: {}", BR::CLIENT_VERSION);
			spdlog::info("sqlite3 version: {} ({})", SQLITE_VERSION, SQLITE_VERSION_NUMBER);
			spdlog::info("cxxopts version: {}", ((CXXOPTS__VERSION_MAJOR * 10000) + (CXXOPTS__VERSION_MINOR * 100) + (SPDLOG_VER_PATCH)));
			spdlog::info("spdlog version: {}", SPDLOG_VERSION);
			exit(0);
		}
	}
	catch (const cxxopts::OptionException& e)
	{
		spdlog::warn(e.what());
		exit(1);
	}

	/* RandSSE Seed */
	srand_sse(time(NULL));

#ifdef _OPENMP
	/*
		Выводим текст в консоль каждым потоком
		Нужно для проверки количества задействованных потоков
	*/
	string s_omp_parallel_cores_test = "";
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

	spdlog::info("Welcome to Battleship Royale Server!");

	/*
		DB initialization
	*/
	MiniDB *mdb = new MiniDB;
	mdb->setTable();
	delete mdb;

	/*
		Start server
	*/
	spdlog::info("Start Battleship Royale Server!");
	spdlog::info("Port: {}", PORT);

	try 
	{
		boost::asio::io_service io_service;   
		Server server(io_service, &PORT);
		io_service.run();
	} 
	catch(std::exception& e) 
	{
		spdlog::error("Error create Server!");
		spdlog::error(e.what());
	}

	return 0;
}
/** @} */