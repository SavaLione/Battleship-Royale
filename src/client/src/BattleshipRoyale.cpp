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

#include "BattleshipRoyale.h"
#include "Args.h"
#include "Client.h"
#include "Window.h"

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
	int LOG_LEVEL = 1;
	int PORT = BR::CONNECT::PORT;
	std::string s_ip = BR::CONNECT::IP;
	std::string s_test = "";

	arg(argc, argv, LOG_LEVEL, PORT, s_ip, s_test);

	/**
	 * Start
	 */
	spdlog::info("Welcome to Battleship Royale Console Client!");

	spdlog::info("IP: {}", s_ip);
	spdlog::info("PORT: {}", PORT);

	// Client ct;
	// ct.setPort(PORT);
	// ct.setIp(s_ip);
	// ct.connect();
	// ct.send(s_test);
	// spdlog::info(ct.receive());

	Window wnw;

	return 0;
}
/** @} */