#ifndef DB_H
#define DB_H

#include <sqlite3.h>

class DB
{
private:
    /* data */
    sqlite3 *db;
    char *zErrMsg = new char;
    int *rc = new int;
    char *messageError;

    /* func */
    void db_open();
    void db_close();
    void db_create();
    bool db_table_check();
public:

    /* func */
    DB(/* args */);

    /* des */
    ~DB();
};

#endif // DB_H