/**
 * @file
 * @brief Работа с базой данных
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
    db_open();

    if (db_table_check())
    {
        spdlog::info("Table found");
    }
    else
    {
        spdlog::warn("Table not found. Create table");
        db_create();
        spdlog::warn("Creating the initial data in the database");
    }

    db_close();
}

/**
 * @brief Деструктор класса
 */
DB::~DB()
{
    delete zErrMsg;
    delete rc;
    delete id;
}

/**
 * @brief Открытие базы данных
 */
void DB::db_open()
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
    spdlog::info("DataBase close");
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

    if (*rc == 0)
    {
        return false;
    }

    return true;
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
    std::string sql = "SELECT ID, NAME FROM PLAYER WHERE NAME = \"";
    sql += *s_name;
    sql += "\"";

    const char *tail;

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        spdlog::warn("DB name: {} found. ID: {}", sqlite3_column_text(stmt, 1), sqlite3_column_int(stmt, 0));
        return true;
    }

    return false;
}

/**
 * @brief Создать пользователя l
 * @param [in] l пользователь
 */
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
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    sql += buf;
    sql += "'";
    sql += ",";

    sql += "0, 0, 0);";

    *rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if (*rc != SQLITE_OK)
    {
        spdlog::error("Failed to create player: {}", l->s_name);
        spdlog::error("Error: {}", sqlite3_errmsg(db));
    }
    else
    {
        spdlog::info("Player {} successfully created.", l->s_name);
    }
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
    sql += "\"";

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        i_ret = sqlite3_column_int(stmt, 0);
    }

    return i_ret;
}

/**
 * @brief Получение UID пользователя
 * @param [in] l пользователь
 * @return UID
 */
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

/**
 * @brief Получение UID пользователя
 * @param [in] l пользователь
 * @param [in] id id
 * @return UID
 */
UID DB::uid_get_np(login *l, int *id)
{
    UID uid_ret;
    uid_ret.s_name = l->s_name;
    uid_ret.co_uid.id = db_get_id(&l->s_name);
    uid_ret.co_uid.u_i_random = *id;

    return uid_ret;
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
    sql += "\"";

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
    sql += "\"";

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
    sql += "\"";

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
    sql += "\"";

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
    sql += "\"";

    *rc = sqlite3_prepare_v2(db, sql.c_str(), 1000, &stmt, &tail);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        i_ret = sqlite3_column_int(stmt, 0);
    }

    return i_ret;
}
/** @} */