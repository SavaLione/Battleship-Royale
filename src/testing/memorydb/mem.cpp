#include <iostream>
#include <string>

#include <sqlite3.h>

#include "BattleshipRoyale.h"

using namespace std;

const char DB_NAME[] = "file:memdb1?mode=memory&cache=shared";

void test();

int main()
{
    string sql = "";

    sqlite3 *db;
    sqlite3_open(DB_NAME, &db);

    sql =
        "CREATE TABLE PLAYER("
        "ID INT PRIMARY KEY     NOT NULL, "
        "NAME           TEXT    NOT NULL, "
        "PASSWORD       TEXT    NOT NULL, "
        "REG_DATE       TEXT    NOT NULL, "
        "SCORE INT      KEY     NOT NULL, "
        "MONEY INT      KEY     NOT NULL, "
        "LEVEL INT      KEY     NOT NULL  "
        ");";
    
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sql = BR::SQLITE3_TEST_DATA;

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);



    test();

    sqlite3_close(db);
    return 0;
}

void test()
{
    string name = "SavaLione", sha2_ret = "";

    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *tail;
    std::string sql = BR::SQLITE3_PRAGMA;

    sqlite3_open(DB_NAME, &db);
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sql = "SELECT PASSWORD FROM PLAYER WHERE NAME =\"";
    sql += name;
    sql += "\";";

    sqlite3_prepare_v2(db, sql.c_str(), BR::SQLITE3_MAX_MESSAGE_SIZE, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        sha2_ret = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    cout << "sha2_ret " << sha2_ret << endl;
}