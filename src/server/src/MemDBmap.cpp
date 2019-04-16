/**
 * @file
 * @brief Облегчённый класс для работы с бд в памяти
 * @author SavaLione
 * @date 16 Apr 2019
 */
/**
 * @defgroup memdbmap_cpp MemDBmap.cpp
 * @ingroup server
 * @{
 */
#include "MemDBmap.h"

#include <string>

#include <sqlite3.h>

#include "BattleshipRoyale.h"

MemDBmap::MemDBmap()
{
}

MemDBmap::~MemDBmap()
{
}

void MemDBmap::create()
{
    std::string sql = "";

    sqlite3 *db;
    sqlite3_open(BR::SQLITE3_DB_MEMORY_MAP_NAME, &db);

    sql = BR::SQLITE3_DB_MEMORY_MAP_TABLE;

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sql = BR::SQLITE3_DB_MEMORY_MAP_DATA;

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sqlite3_close(db);
}

/** @} */