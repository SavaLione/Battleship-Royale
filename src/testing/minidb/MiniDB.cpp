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
    sqlite3_open(BR::DB_NAME, &db);

    *sql = BR::SQLITE3_PRAGMA;
    request(sql);
}

/**
 * @brief Деструктор класса
 */
MiniDB::~MiniDB()
{
    delete rc;
    delete sql;
}

void MiniDB::close()
{
    sqlite3_close(db);
}

/**
 * @brief Проверка существования пользователя
 * @param [in] name имя пользователя
 * @return true - пользователь существует, false - пользователь не существует.
 */
bool MiniDB::checkPlayer(std::string *name)
{
    *sql = "SELECT NAME FROM PLAYER WHERE NAME = \"";
    *sql += *name;
    *sql += "\";";

    //const char *tail;

    //*rc = sqlite3_prepare_v2(db, s_sql->c_str(), 1000, &stmt, &tail);
    sqlite3_prepare_v2(db, sql->c_str(), 1000, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        return true;
    }

    return false;
}

/**
 * @brief Получение пароля по имени
 * @param [in] name имя пользователя
 * @param [out] sha2_ret пароль (из бд. в sha2)
 */
void MiniDB::getPassword(std::string *name, std::string *sha2_ret)
{
    //const char *tail;

    *sql = "SELECT PASSWORD FROM PLAYER WHERE NAME =\"";
    *sql += *name;
    *sql += "\";";

    sqlite3_prepare_v2(db, sql->c_str(), 1000, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        *sha2_ret = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
    }
}

/**
 * @brief Инициализация базы данных
 */
void MiniDB::setTable()
{
    *sql = BR::SQLITE3_PRAGMA;
    request(sql);

    *sql =
        "CREATE TABLE PLAYER("
        "ID INT PRIMARY KEY     NOT NULL, "
        "NAME           TEXT    NOT NULL, "
        "PASSWORD       TEXT    NOT NULL, "
        "REG_DATE       TEXT    NOT NULL, "
        "SCORE INT      KEY     NOT NULL, "
        "MONEY INT      KEY     NOT NULL, "
        "LEVEL INT      KEY     NOT NULL  "
        ");";
    *rc = sqlite3_exec(db, sql->c_str(), NULL, 0, NULL);
    if (*rc == 0)
    {
        *sql = BR::SQLITE3_TEST_DATA;
        request(sql);
    }
}
/** @} */