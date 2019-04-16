/**
 * @file
 * @brief Облегчённый класс для работы с бд
 * @author SavaLione
 * @date 15 Apr 2019
 */
/**
 * @defgroup minidb_cpp MiniDB.cpp
 * @ingroup server
 * @{
 */
#include "MiniDB.h"

#include <time.h>

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
bool MiniDB::checkPlayer(std::string const& name)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *tail;
    std::string sql = BR::SQLITE3_PRAGMA;

    bool fl = false;

    sqlite3_open(BR::DB_NAME, &db);

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sql = "SELECT NAME FROM PLAYER WHERE NAME = \"";
    sql += name;
    sql += "\";";

    sqlite3_prepare_v2(db, sql.c_str(), BR::SQLITE3_MAX_MESSAGE_SIZE, &stmt, &tail);

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
void MiniDB::getPassword(std::string const& name, std::string& sha2_ret)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *tail;
    std::string sql = BR::SQLITE3_PRAGMA;

    sqlite3_open(BR::DB_NAME, &db);
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

    rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sql = BR::SQLITE3_TEST_TABLE;
    
    rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
    if (rc == 0)
    {
        sql = BR::SQLITE3_TEST_DATA;
        rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
    }

    sqlite3_close(db);
}

/**
 * @brief Создание пользователя
 * @param [in] name имя пользователя
 * @param [in] sha2 пароль (в sha2)
 */
void MiniDB::createPlayer(std::string const& name, std::string const& sha2)
{
	time_t t;
	time(&t);

    sqlite3 *db;
    std::string sql = "";

    sql += "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, '";
    sql += name;
    sql += "', '";
    sql += sha2;
    sql += "', '";
    sql += ctime(&t);
    sql += "', 0, 0, 0);";

    sqlite3_open(BR::DB_NAME, &db);

    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);

    sqlite3_close(db);
}
/** @} */