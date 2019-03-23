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
        db_create();
        spdlog::warn("Creating the initial data in the database");
    }

    spdlog::info(db_id_check());

    db_add_some();

    db_close();
}

DB::~DB()
{
    delete zErrMsg;
    delete rc;
    delete id;
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
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY) VALUES(1, 'ZERO', 'ZEROZERO', 'ZERO', 0, 0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'SavaLione', 'MyOwOpass', 'now', 0, 0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'OwO', 'OwO', '1234d', 0, 0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'UwU', 'UwU', 'a', 0, 0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Hewwwoo', 'Hiii', 'n', 0, 0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Awwww', 'Awwwwwwwwwwwww', 'www', 1234, 1234);";
    
    *rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if(*rc != SQLITE_OK)
    {
        spdlog::warn("Failed to create initial entries in the database: {}", sqlite3_errmsg(db));
    }
    else
    {
        spdlog::info("Initial data in database successfully created.");
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

int DB::db_id_check()
{
    /*
    std::string sql = "SELECT count(*) FROM PLAYER";

    *rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    spdlog::error("rc id: {}", *rc);
    spdlog::error("rc id: {}", *rc);
    */
   const char *tail;

    std::string sql = "SELECT ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY from PLAYER";

   *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);

    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        spdlog::info("ID: {}", sqlite3_column_text(stmt, 0));
        spdlog::info("NAME: {}", sqlite3_column_text(stmt, 1));
        spdlog::info("PASSWORD: {}", sqlite3_column_text(stmt, 2));
        spdlog::info("REG_DATE: {}", sqlite3_column_text(stmt, 3));
        spdlog::info("SCORE: {}", sqlite3_column_text(stmt, 4));
        spdlog::info("MONEY: {}", sqlite3_column_text(stmt, 5));
        spdlog::info("------------------");
    }

    return 0;
}

void DB::db_add_some()
{
    std::string sql =
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'ZEROa', 'ZEROZERO', 'ZERO', 100, 100);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'ZEROa', 'ZEROZERO', 'ZERO', 100, 100);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'ZEROa', 'ZEROZERO', 'ZERO', 100, 100);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'ZEROa', 'ZEROZERO', 'ZERO', 100, 100);";
    
    *rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if(*rc != SQLITE_OK)
    {
        spdlog::warn("Error add some. Code: {}", sqlite3_errmsg(db));
    }
}