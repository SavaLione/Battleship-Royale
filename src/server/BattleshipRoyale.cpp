#include <iostream>
#include <string>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <sqlite3.h>

#include <cxxopts.hpp>

#include "BattleshipRoyale.h"
#include "DB.h"

#include "rand_sse.h"

using namespace std;

int main(int argc, char *argv[])
{
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
		Arg opt
	*/
	bool HIDE_LOG = false;
	int PORT = 49939;

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
			spdlog::info(BR::VERSION_SERVER);
			spdlog::info(BR::VERSION_DATABASE);
			exit(0);
		}
	}
	catch (const cxxopts::OptionException& e)
	{
		spdlog::warn(e.what());
		exit(1);
	}

	/*
		Start server
	*/
	spdlog::info("Start Battleship Royale Server!");
	spdlog::info("Port: {}", PORT);

	// Тест базы данных
	DB *db_test = new DB;
	delete db_test;

	return 0;
}

/*
	Можно создать 2 вектора
	Вектор под очередь из игроков
	И вектор из векторов - карта

	vector<Player> vec_Player;
	vector<vector<Map>> vec_Map;

	Игроки, которые ожидают игру, добавляются в вектор vec_Player
	По истечении времени, игроки отсекаются и закидываются на карту
	
	--------------------------
	1. vec_Player		|a|b|f|e|z|x|q|
	2. timer					|--------------> Map
	3. wait				|z|x|q|
	--------------------------
*/

/*
	Short description of the machine

	MainCycle cycle;
	cycle.Start();
	while (!cycle.Exit)
	{
		cycle.Update();
	}
	cycle.End();
	delete cycle;
*/