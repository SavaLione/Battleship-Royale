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

#include <string>

#include <sqlite3.h>

#include "BattleshipRoyale.h"

MemDBuid::MemDBuid()
{
}

MemDBuid::~MemDBuid()
{
}

void MemDBuid::create()
{
    std::string sql = "";

    sqlite3 *db;
    sqlite3_open(BR::SQLITE3_DB_MEMORY_UID_NAME, &db);

    sql = BR::SQLITE3_DB_MEMORY_UID_TABLE;

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sql = BR::SQLITE3_DB_MEMORY_UID_DATA;

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sqlite3_close(db);
}

/** @} */