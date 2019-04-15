/**
 * @file
 * @brief Облегчённый класс для работы с бд
 * @author SavaLione
 * @date 14 Apr 2019
 */
/**
 * @defgroup minidb_cpp MiniDB.cpp
 * @ingroup server
 * @{
 */
#include "MiniDB.h"

/**
 * @brief Конструктор класса
 */
MiniDB::MiniDB()
{
}

/**
 * @brief Деструктор класса
 */
MiniDB::~MiniDB()
{
}

/**
 * @brief Проверка существования пользователя
 * @param [in] name имя пользователя
 * @return true - пользователь существует, false - пользователь не существует.
 */
bool MiniDB::checkPlayer(std::string *name)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *tail;
    std::string sql = BR::SQLITE3_PRAGMA;

    bool fl = false;

    sqlite3_open(BR::DB_NAME, &db);

    request(db, &sql);

    sql = "SELECT NAME FROM PLAYER WHERE NAME = \"";
    sql += *name;
    sql += "\";";

    sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        fl = true;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return fl;
}

/**
 * @brief Получение пароля по имени
 * @param [in] name имя пользователя
 * @param [out] sha2_ret пароль (из бд. в sha2)
 */
void MiniDB::getPassword(std::string *name, std::string *sha2_ret)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *tail;
    std::string sql = BR::SQLITE3_PRAGMA;

    sqlite3_open(BR::DB_NAME, &db);
    request(db, &sql);

    sql = "SELECT PASSWORD FROM PLAYER WHERE NAME =\"";
    sql += *name;
    sql += "\";";

    sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        *sha2_ret = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

/**
 * @brief Инициализация базы данных
 */
void MiniDB::setTable()
{
    sqlite3 *db;
    int rc = 0;
    std::string sql = BR::SQLITE3_PRAGMA;
    
    sqlite3_open(BR::DB_NAME, &db);

    //sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
    request(db, &sql);

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
    
    //rc = sqlite3_exec(db, sql.c_str(), NULL, 0, NULL);
    request(db, &sql, &rc);
    if (rc == 0)
    {
        sql = BR::SQLITE3_TEST_DATA;
        //sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
        request(db, &sql);
    }

    sqlite3_close(db);
}

/** @} */