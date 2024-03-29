/**
 * @file
 * @brief Работа с базой данных
 * @deprecated
 * @author SavaLione
 * @date 14 Apr 2019
 */
/**
 * @defgroup dbcpp DB.cpp
 * @ingroup server
 * @{
 */
#include <string>
#include <ctime>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <picosha2.h>

#include "DB.h"
#include "BattleshipRoyale.h"

#include "rand_sse.h"

/**
 * @brief Конструктор класса
 */
DB::DB(/* args */)
{
    // OPEN
    *rc = sqlite3_open(BR::DB_NAME, &db);

    // PRAGMA
    *s_sql = BR::SQLITE3_PRAGMA;
    *rc = sqlite3_exec(db, s_sql->c_str(), NULL, 0, &messageError);
}

/**
 * @brief Деструктор класса
 */
DB::~DB()
{
    delete zErrMsg;
    delete rc;
    delete id;
    delete s_sql;
    db_close();
}

/**
 * @brief Проверка бд(получается открыть?)
 */
void DB::db_open_log()
{
    *rc = sqlite3_open(BR::DB_NAME, &db);

    if (*rc)
    {
        spdlog::error("Can't open database: {}", sqlite3_errmsg(db));
    }
    else
    {
        spdlog::info("Opened database successfully");
    }
}

/**
 * @brief Закытие базы данных
 */
void DB::db_close()
{
    sqlite3_close(db);
}

/**
 * @brief Создание базы данных
 */
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

    if (*rc != SQLITE_OK)
    {
        spdlog::error("Failed to create initial entries in the database: {}", sqlite3_errmsg(db));
    }
    else
    {
        spdlog::info("Initial data in database successfully created.");
    }
}

/**
 * @brief Проверка существования таблицы Player
 */
void DB::db_table_check()
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

    if (*rc != 0)
    {
        spdlog::info("Table found");
    }
    else
    {
        spdlog::warn("Table not found. Create table");
        db_create();
        spdlog::warn("Creating the initial data in the database");
    }
}

/**
 * @brief Вывод всех пользователей с информацией в консоль
 */
void DB::db_all_check()
{
    const char *tail;

    std::string sql = "SELECT ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL from PLAYER";

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);

    while (sqlite3_step(stmt) == SQLITE_ROW)
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

/**
 * @brief Проверка существования пользователя
 * @param [in] s_name имя пользователя
 * @return true - пользователь существует, false - пользователь не существует.
 */
bool DB::db_check_player(std::string *s_name)
{
    *s_sql = "SELECT NAME FROM PLAYER WHERE NAME = \"";
    *s_sql += *s_name;
    *s_sql += "\";";

    //const char *tail;

    //*rc = sqlite3_prepare_v2(db, s_sql->c_str(), 1000, &stmt, &tail);
    *rc = sqlite3_prepare_v2(db, s_sql->c_str(), 1000, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        return true;
    }

    return false;
}

/**
 * @brief Проверка пароля
 * @param [in] name имя пользователя
 * @param [in] pass пароль
 * @return true - пароль правильный, false - пароль не правильный.
 */
bool DB::db_check_pass(std::string *name, std::string *pass)
{
    if (db_get_password(name) == *pass)
    {
        return true;
    }
    return false;
}

/**
 * @brief Получить карточку пользователя db_player по ссылке
 * @param [in] name имя пользователя
 * @param [out] pl карточка пользователя
 */
void DB::db_get_player(std::string *name, db_player *pl)
{
    const char *tail;

    std::string sql = "SELECT ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL FROM PLAYER WHERE NAME =\"";
    sql += *name;
    sql += "\"";

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {

        pl->id = sqlite3_column_int(stmt, 0);
        pl->name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        pl->password = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
        pl->reg_date = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)));
        pl->score = sqlite3_column_int(stmt, 4);
        pl->money = sqlite3_column_int(stmt, 5);
        pl->level = sqlite3_column_int(stmt, 6);
    }
}

/**
 * @brief Вывод информации о пользователе по ссылке
 * @param [in] pl имя пользователя
 */
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

/**
 * @brief Создание sha2 по ссылке
 * @param [in] s строка для преобразования в sha2
 * @return sha2 сообщение
 */
std::string DB::sha2(std::string *s)
{
    std::string ret;
    picosha2::hash256_hex_string(*s, ret);
    return ret;
}

/**
 * @brief Получение id пользователя по имени. id уникальный
 * @param [in] s_name имя пользователя
 * @return id пользователя
 */
int DB::db_get_id(std::string *s_name)
{
    int i_ret = -1;
    const char *tail;

    std::string sql = "SELECT ID FROM PLAYER WHERE NAME =\"";
    sql += *s_name;
    sql += "\";";

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        i_ret = sqlite3_column_int(stmt, 0);
    }

    return i_ret;
}

/**
 * @brief Получение даты регистрации по имени
 * @param [in] s_name имя пользователя
 * @return дата регистрации
 */
std::string DB::db_get_reg_date(std::string *s_name)
{
    std::string s_ret = "";
    const char *tail;

    std::string sql = "SELECT REG_DATE FROM PLAYER WHERE NAME =\"";
    sql += *s_name;
    sql += "\";";

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        s_ret = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
    }

    return s_ret;
}

/**
 * @brief Получение пароля по имени
 * @param [in] s_name имя пользователя
 * @return пароль (из бд. в sha2)
 */
std::string DB::db_get_password(std::string *s_name)
{
    std::string s_ret = "";
    const char *tail;

    std::string sql = "SELECT PASSWORD FROM PLAYER WHERE NAME =\"";
    sql += *s_name;
    sql += "\";";

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        s_ret = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
    }

    return s_ret;
}

/**
 * @brief Получение результата по имени
 * @param [in] s_name имя пользователя
 * @return результат(очки)
 */
int DB::db_get_score(std::string *s_name)
{
    int i_ret = -1;
    const char *tail;

    std::string sql = "SELECT SCORE FROM PLAYER WHERE NAME =\"";
    sql += *s_name;
    sql += "\";";

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        i_ret = sqlite3_column_int(stmt, 0);
    }

    return i_ret;
}

/**
 * @brief Получение счёта по имени
 * @param [in] s_name имя пользователя
 * @return счёт
 */
int DB::db_get_money(std::string *s_name)
{
    int i_ret = -1;
    const char *tail;

    std::string sql = "SELECT MONEY FROM PLAYER WHERE NAME =\"";
    sql += *s_name;
    sql += "\";";

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        i_ret = sqlite3_column_int(stmt, 0);
    }

    return i_ret;
}

/**
 * @brief Получение уровня доступа по имени
 * @param [in] s_name имя пользователя
 * @return уровень доступа
 */
int DB::db_get_level(std::string *s_name)
{
    int i_ret = -1;
    const char *tail;

    std::string sql = "SELECT LEVEL FROM PLAYER WHERE NAME =\"";
    sql += *s_name;
    sql += "\";";

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        i_ret = sqlite3_column_int(stmt, 0);
    }

    return i_ret;
}

/**
 * @brief Задать флаги sqlite3. Проверка возможности
 */
void DB::db_PRAGMA_log()
{
    std::string sql = BR::SQLITE3_PRAGMA;
    *rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if (*rc != SQLITE_OK)
    {
        spdlog::error("Failed to use PRAGMA: {}", sqlite3_errmsg(db));
    }
}
/** @} */