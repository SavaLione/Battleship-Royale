#include <iostream>
#include <string>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <sqlite3.h>

#include <cxxopts.hpp>

#include "BattleshipRoyale.h"
#include "Player.h"

using namespace std;

void test_bd();
int create_a_table();
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

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
            spdlog::info(BR::VERSION);
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
    
    //test_bd();
    int i = create_a_table();

    spdlog::info("I: {}", i);

    return 0;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int create_a_table() {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(db);
   return 0;
}

void test_bd()
{
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if(rc) {
        spdlog::warn("Can't open database: {}", sqlite3_errmsg(db));
    } else {
        spdlog::info("Opened database successfully");
    }
    sqlite3_close(db);
}