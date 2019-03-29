#ifndef DB_H
#define DB_H

#include <sqlite3.h>

struct db_player
{
    int id;
    std::string name;
    std::string password;
    std::string reg_date;
    int score;
    int money;
    int level;
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

    /* Some */
    //void db_add_some();

    /* Вывод информации о пользователе поссылке */
    void db_get_player_print(db_player *pl);

    /* Создание sha2 по ссылке */
    std::string sha2(std::string *s);
public:
    /* func */

    DB();

    /* Создать пользователя s_name с паролем s_password */
    void db_add_player(std::string s_name, std::string s_password);

    /* Проверка существования пользователя s_name */
    bool db_check_player(std::string s_name);

    /* Получить карточку пользователя db_player по ссылке */
    void db_get_player(std::string name, db_player *pl);

    /* des */
    ~DB();
};

#endif // DB_H