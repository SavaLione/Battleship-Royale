/**
 * @file
 * @brief Облегчённый класс для работы с бд в памяти
 * @author SavaLione
 * @date 16 Apr 2019
 */
/**
 * @defgroup memdbuid_cpp MemDBuid.cpp
 * @ingroup server
 * @{
 */
#include "MemDBuid.h"

#include <ctime>

#include <sqlite3.h>
#include <picosha2.h>

#include "BattleshipRoyale.h"

MemDBuid::MemDBuid()
{
}

MemDBuid::~MemDBuid()
{
}

    // bool checkUid(std::string const& uid);
    // bool ifFoundUid(std::string const& uid);
    // bool ifFoundName(std::string const& name);

bool MemDBuid::ifFoundName(std::string const& name)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *tail;
    std::string sql = "";

    bool fl = false;

    sqlite3_open(BR::SQLITE3::MEMORY::UID, &db);

    sql = "SELECT UID FROM UID WHERE NAME = \"";
    sql += name;
    sql += "\";";

    sqlite3_prepare_v2(db, sql.c_str(), BR::SQLITE3::MAX_MESSAGE_SIZE, &stmt, &tail);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        fl = true;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return fl;
}

bool MemDBuid::ifFoundUid(std::string const& uid)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *tail;
    std::string sql = "";

    bool fl = false;

    sqlite3_open(BR::SQLITE3::MEMORY::UID, &db);

    sql = "SELECT NAME FROM UID WHERE UID = \"";
    sql += uid;
    sql += "\";";

    sqlite3_prepare_v2(db, sql.c_str(), BR::SQLITE3::MAX_MESSAGE_SIZE, &stmt, &tail);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        fl = true;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return fl;
}

void MemDBuid::setUid(std::string const& name)
{
    std::string hash_hex_str = "", tosha2 = BR::SQLITE3::MEMORY::UID_SECRET_CODE;
    std::time_t t = std::time(nullptr);
    tosha2 += std::to_string(t);
    tosha2 += name;

    picosha2::hash256_hex_string(tosha2, hash_hex_str);

    setUid(name, hash_hex_str);
}

void MemDBuid::setUid(std::string const& name, std::string const& uid)
{
    std::string sql = "";

    sqlite3 *db;
    sqlite3_open(BR::SQLITE3::MEMORY::UID, &db);

    sql = "INSERT INTO UID (ID, UID, NAME) VALUES((SELECT max(ID) FROM UID) + 1, '";
    sql += uid;
    sql += "', '";
    sql += name;
    sql += "');";

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sqlite3_close(db);
}

std::string MemDBuid::getUid(std::string const& name)
{
    std::string ret = "", sql = "";
    
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *tail;
    //std::string sql = BR::SQLITE3::PRAGMA;

    sqlite3_open(BR::SQLITE3::MEMORY::UID, &db);
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sql = "SELECT UID FROM UID WHERE NAME =\"";
    sql += name;
    sql += "\";";

    sqlite3_prepare_v2(db, sql.c_str(), BR::SQLITE3::MAX_MESSAGE_SIZE, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        ret = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return ret;
}

std::string MemDBuid::getName(std::string const& uid)
{
    std::string ret = "", sql = "";
    
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *tail;
    //std::string sql = BR::SQLITE3::PRAGMA;

    sqlite3_open(BR::SQLITE3::MEMORY::UID, &db);
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sql = "SELECT NAME FROM UID WHERE UID =\"";
    sql += uid;
    sql += "\";";

    sqlite3_prepare_v2(db, sql.c_str(), BR::SQLITE3::MAX_MESSAGE_SIZE, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        ret = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return ret;
}

void MemDBuid::create()
{
    std::string sql = "";

    sqlite3 *db;
    sqlite3_open(BR::SQLITE3::MEMORY::UID, &db);

    sql = BR::SQLITE3::MEMORY::TABLE_UID;

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sql = BR::SQLITE3::MEMORY::DATA_UID;

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sqlite3_close(db);
}

void MemDBuid::del()
{
    std::string sql = "";

    sqlite3 *db;
    sqlite3_open(BR::SQLITE3::MEMORY::UID, &db);

    sql = "DROP TABLE UID;";

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sqlite3_close(db);
}

/** @} */