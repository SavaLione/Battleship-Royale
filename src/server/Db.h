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
    void db_open();
    void db_close();
    void db_create();
    bool db_table_check();
    void db_all_check();
    void db_add_some();
    void db_get_player_print(db_player *pl);
    std::string sha2(std::string *s);
public:

    /* func */
    DB(/* args */);
    void db_add_player(std::string s_name, std::string s_password);
    bool db_check_player(std::string s_name);
    void db_get_player(std::string name, db_player *pl);

    /* des */
    ~DB();
};

#endif // DB_H