#include <iostream>
#include <string>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <sqlite3.h>
#include <boost/asio.hpp>

#include <cxxopts.hpp>

#include "BattleshipRoyale.h"
#include "Player.h"
#include "Db.h"

using namespace std;

int main(int argc, char *argv[])
{
    spdlog::info("Welcome to Battleship Royale Server!");
    /*
        Arg opt
    */
    bool HIDE_LOG = false;
    int PORT = 49939;

    try
    {
        cxxopts::Options options("BattleshipRoyaleServer", " - Battleship Royale Server");

        options.add_options()
		    ("h,help", 		"Help"											)
            ("v,version", 	"Version"										)
		    ("l,log", 		"Log", 			cxxopts::value<bool>(HIDE_LOG)	)
            ("p,port", 		"Port", 		cxxopts::value<int>(PORT)	    );

        auto result = options.parse(argc, argv);

        if(result.count("help"))
        {
            spdlog::info(options.help({"", "Group"}));
            exit(0);
        }

        if(result.count("version"))
        {
            spdlog::info(BR::VERSION_SERVER);
            spdlog::info(BR::VERSION_DATABASE);
            exit(0);
        }
    } catch (const cxxopts::OptionException& e)
    {
        spdlog::warn(e.what());
        exit(1);
    }

    /*
        Start server
    */
    spdlog::info("Start Battleship Royale Server!");
    spdlog::info("Port: {}", PORT);

    DB *db_test = new DB;
    
    delete db_test;

    return 0;
}