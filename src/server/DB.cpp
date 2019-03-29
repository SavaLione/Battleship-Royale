#include <string>
#include <ctime>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <picosha2.h>

#include "DB.h"
#include "BattleshipRoyale.h"

#include "rand_sse.h"

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

    // UID DB::uid_get_np(login *l)

    login l;
    l.s_name = "SavaLione";
    l.s_password = "some";

    UID uid_test = uid_get_np(&l);
    
    spdlog::info("uid_test.s_name {}", uid_test.s_name);
    spdlog::info("uid_test.co_uid.id {}", uid_test.co_uid.id);
    spdlog::info("uid_test.co_uid.u_i_random {}", uid_test.co_uid.u_i_random);

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
        spdlog::error("Can't open database: {}", sqlite3_errmsg(db));
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
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES(1, 'ZERO', 'ZEROZERO', 'ZERO', 1, 1, 1);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'SavaLione', 'MyOwOpass', 'now', 0, 0, 7);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'OwO', 'OwO', '1234d', 0, 0, 0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'UwU', 'UwU', 'a', 0, 0, 0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Hewwwoo', 'Hiii', 'n', 0, 0, 0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Awwww', 'Awwwwwwwwwwwww', 'www', 1234, 1234, 0);";
    
    *rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if(*rc != SQLITE_OK)
    {
        spdlog::error("Failed to create initial entries in the database: {}", sqlite3_errmsg(db));
    }
    else
    {
        spdlog::info("Initial data in database successfully created.");
    }
}

bool DB::db_table_check()
{
    std::string sql = 
        "CREATE TABLE PLAYER("
        "ID INT PRIMARY KEY     NOT NULL, "
        "NAME           TEXT    NOT NULL, "
        "PASSWORD       TEXT    NOT NULL, "
        "REG_DATE       TEXT    NOT NULL, "
        "SCORE INT      KEY     NOT NULL, "
        "MONEY INT      KEY     NOT NULL, "
        "LEVEL INT      KEY     NOT NULL  "
        ");";

    *rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if(*rc == 0)
    {
        return false;
    }

   return true;
}

void DB::db_all_check()
{
    const char *tail;

    std::string sql = "SELECT ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL from PLAYER";

   *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);

    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        spdlog::info("ID: {}", sqlite3_column_int(stmt, 0));
        spdlog::info("NAME: {}", sqlite3_column_text(stmt, 1));
        spdlog::info("PASSWORD: {}", sqlite3_column_text(stmt, 2));
        spdlog::info("REG_DATE: {}", sqlite3_column_text(stmt, 3));
        spdlog::info("SCORE: {}", sqlite3_column_int(stmt, 4));
        spdlog::info("MONEY: {}", sqlite3_column_int(stmt, 5));
        spdlog::info("LEVEL: {}", sqlite3_column_int(stmt, 6));
        spdlog::info("------------------");
    }
}

bool DB::db_check_player(std::string *s_name)
{
    std::string sql = "SELECT ID, NAME FROM PLAYER WHERE NAME = \"";
    sql += *s_name;
    sql += "\"";
    
    const char *tail;

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);

    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        spdlog::warn("DB name: {} found. ID: {}", sqlite3_column_text(stmt, 1), sqlite3_column_int(stmt, 0));
        return true;
    }

    return false;
}

void DB::db_add_player(login *l)
{
    std::string sql =
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1,";

    sql += "'";
    sql += l->s_name;
    sql += "'";
    sql += ",";

    sql += "'";
    sql += sha2(&l->s_password);
    sql += "'";
    sql += ",";

    sql += "'";
    time_t  now = time(0);
    struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    sql += buf;
    sql += "'";
    sql += ",";

    sql += "0, 0, 0);";

    *rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if(*rc != SQLITE_OK)
    {
        spdlog::error("Failed to create player: {}", l->s_name);
        spdlog::error("Error: {}", sqlite3_errmsg(db));
    }
    else
    {
        spdlog::info("Player {} successfully created.", l->s_name);
    }

}

void DB::db_get_player(std::string *name, db_player *pl)
{
    const char *tail;

    std::string sql = "SELECT ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL FROM PLAYER WHERE NAME =\"";
    sql += *name;
    sql += "\"";

   *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);

    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        
        pl->id = sqlite3_column_int(stmt, 0);
        pl->name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        pl->password = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        pl->reg_date = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        pl->score = sqlite3_column_int(stmt, 4);
        pl->money = sqlite3_column_int(stmt, 5);
        pl->level = sqlite3_column_int(stmt, 6);
    }
}

void DB::db_get_player_print(db_player *pl)
{
    spdlog::info("id: {}", pl->id);
    spdlog::info("name: {}", pl->name);
    spdlog::info("password: {}", pl->password);
    spdlog::info("reg_date: {}", pl->reg_date);
    spdlog::info("score: {}", pl->score);
    spdlog::info("money: {}", pl->money);
    spdlog::info("level: {}", pl->level);
}

std::string DB::sha2(std::string *s)
{
    std::string ret;
    picosha2::hash256_hex_string(*s, ret);
    return ret;
}

int DB::db_get_id(std::string *s_name)
{
    int i_ret = -1;
    const char *tail;

    std::string sql = "SELECT ID FROM PLAYER WHERE NAME =\"";
    sql += *s_name;
    sql += "\"";

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);
    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        i_ret = sqlite3_column_int(stmt, 0);
    }

   return i_ret;
}

UID DB::uid_get_np(login *l)
{
    unsigned int u_i_random[4];
    rand_sse(u_i_random);

    UID uid_ret;
    uid_ret.s_name = l->s_name;
    uid_ret.co_uid.id = db_get_id(&l->s_name);
    uid_ret.co_uid.u_i_random = u_i_random[0];

    return uid_ret;
}
UID DB::uid_get_np(login *l, int *id)
{
    UID uid_ret;
    uid_ret.s_name = l->s_name;
    uid_ret.co_uid.id = db_get_id(&l->s_name);
    uid_ret.co_uid.u_i_random = *id;

    return uid_ret;
}