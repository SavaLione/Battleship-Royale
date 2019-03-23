#include <string>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include "Db.h"
#include "BattleshipRoyale.h"

DB::DB(/* args */)
{
    db_open();

    if(db_table_check())
    {
        spdlog::info("Table found");
    }
    else
    {
        spdlog::warn("Table not found. Create table");
    }

    

    db_close();
}

DB::~DB()
{
    delete zErrMsg;
    delete rc;
}

void DB::db_open()
{
    *rc = sqlite3_open(BR::DB_NAME, &db);

    if(*rc) {
        spdlog::warn("Can't open database: {}", sqlite3_errmsg(db));
    } else {
        spdlog::info("Opened database successfully");
    }
}

void DB::db_close()
{
    sqlite3_close(db);
    spdlog::info("DataBase close");
}

void DB::db_create()
{
    std::string sql = 
        "CREATE TABLE PLAYER("
        "ID INT PRIMARY KEY     NOT NULL, "
        "NAME           TEXT    NOT NULL, "
        "PASSWORD       TEXT    NOT NULL, "
        "REG_DATE       TEXT    NOT NULL, "
        "SCORE INT      KEY     NOT NULL, "
        "MONEY INT      KEY     NOT NULL "
        ");";
    
    *rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if(*rc != SQLITE_OK)
    {
        spdlog::warn("Error create table. Code: {}", sqlite3_errmsg(db));
    }
    else
    {
        spdlog::info("Table create");
    }
}

bool DB::db_table_check()
{
    /*
    std::string sql = 
        "INSERT INTO PLAYER VALUES(0, 'ZERO', 'ZEROZERO', 'ZERO', 100, 100);"
        "INSERT INTO PLAYER VALUES(1, 'SavaLione', 'MYPASS', 'NOW', 200, 1000);"
        "INSERT INTO PLAYER VALUES(2, 'Admin', 'Admin', 'OwO', 0, 0);";
    
    *rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if(*rc != SQLITE_OK)
    {
        spdlog::warn("Error create table. Code: {}", sqlite3_errmsg(db));
        return false;
    }
    return true;
    */
    std::string sql = 
        "CREATE TABLE PLAYER("
        "ID INT PRIMARY KEY     NOT NULL, "
        "NAME           TEXT    NOT NULL, "
        "PASSWORD       TEXT    NOT NULL, "
        "REG_DATE       TEXT    NOT NULL, "
        "SCORE INT      KEY     NOT NULL, "
        "MONEY INT      KEY     NOT NULL "
        ");";

    *rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if(*rc == 0)
    {
        return false;
    }

   return true;
}