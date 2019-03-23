#ifndef DB_H
#define DB_H

#include <sqlite3.h>

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
    int db_id_check();
    void db_add_some();
public:

    /* func */
    DB(/* args */);

    /* des */
    ~DB();
};

#endif // DB_H