#ifndef DB_H
#define DB_H

#include <sqlite3.h>

#include "BattleshipRoyale.h"

/* Карточка пользователя */
struct db_player
{
    /* id */
    int id;

    /* Имя */
    std::string name;

    /* Пароль */
    std::string password;

    /* Дата регистрации */
    std::string reg_date;

    /* Очки */
    int score;

    /* Валюта */
    int money;

    /*
        Уровень доступа
            0   -   Пользователи
            1   -   Бета
            3   -   Админ
    */
    int level;
};

struct login
{
   std::string s_name;
   std::string s_password;
};

class DB
{
private:
    /* data */
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *zErrMsg = new char;
    int *rc = new int;
    int *id = new int;
    char *messageError;

    /* func */

    /* Открытие базы данных */
    void db_open();

    /* Закытие базы данных */
    void db_close();

    /* Создание базы данных */
    void db_create();

    /* Проверка существования таблицы Player */
    bool db_table_check();

    /* Вывод всех пользователей с информацией в консоль */
    void db_all_check();

    /* Вывод информации о пользователе по ссылке */
    void db_get_player_print(db_player *pl);

    /* Создание sha2 по ссылке */
    std::string sha2(std::string *s);
public:
    /* func */

    DB();

    /* Создать пользователя l */
    void db_add_player(login *l);

    /* Проверка существования пользователя s_name */
    bool db_check_player(std::string *s_name);

    /* Получить карточку пользователя db_player по ссылке */
    void db_get_player(std::string *name, db_player *pl);

    /* Получение id пользователя по имени. id уникальный */
    int db_get_id(std::string *s_name);

    /* Проверка пароля */
    bool db_check_pass(login *l);

    /* Получение UID пользователя */
    UID uid_get_np(login *l);
    UID uid_get_np(login *l, int *id);

    /* Получение даты регистрации по имени */
    std::string db_get_reg_date(std::string *s_name);

    /* Получение пароля по имени */
    std::string db_get_password(std::string *s_name);

    /* Получение результата по имени */
    int db_get_score(std::string *s_name);

    /* Получение счёта по имени */
    int db_get_money(std::string *s_name);

    /* Получение уровня доступа по имени */
    int db_get_level(std::string *s_name);


    /* des */
    ~DB();
};

#endif // DB_H