#include <iostream>
#include <string>

#include <sqlite3.h>

#include "BattleshipRoyale.h"

using namespace std;

const char DB_NAME[] = "file:memdb1?mode=memory&cache=shared";
const char DB_NAME_TWO[] = "file:memdb2?mode=memory&cache=shared";

void test();
void test_two();

int main()
{
    string sql = "";

    sqlite3 *db;
    sqlite3_open(DB_NAME, &db);

    sqlite3 *db_two;
    sqlite3_open(DB_NAME_TWO, &db_two);



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
    sqlite3_exec(db_two, sql.c_str(), NULL, NULL, NULL);

    sql =
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES(1,                                'ZERO',      'ZEROZERO',       'ZERO',  1,    1,    1);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'SavaLione', 'MyOwOpass',      'now',   0,    0,    7);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'OwO',       'OwO',            '1234d', 0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'UwU',       'UwU',            'a',     0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Hewwwoo',   'Hiii',           'n',     0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Awwww',     'Awwwwwwwwwwwww', 'www',   1234, 1234, 0);";

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sql =
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES(1,                                'ZERO',      'ZEROZERO',       'ZERO',  1,    1,    1);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'SavaLione', 'TWO',            'now',   0,    0,    7);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'OwO',       'OwO',            '1234d', 0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'UwU',       'UwU',            'a',     0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Hewwwoo',   'Hiii',           'n',     0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Awwww',     'Awwwwwwwwwwwww', 'www',   1234, 1234, 0);";

    sqlite3_exec(db_two, sql.c_str(), NULL, NULL, NULL);


    test();
    test_two();

    sqlite3_close(db);
    sqlite3_close(db_two);
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

void test_two()
{
    string name = "SavaLione", sha2_ret = "";

    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *tail;
    std::string sql = BR::SQLITE3_PRAGMA;

    sqlite3_open(DB_NAME_TWO, &db);
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

    cout << "sha2_ret_two " << sha2_ret << endl;
}