#ifndef BATTLESHIPROYALE_H
#define BATTLESHIPROYALE_H

struct Pos
{
    int i_x;
    int i_y;

};

struct Size
{
    int i_x;
    int i_y;

};

/*
    ################################
    # BR Константы
    ################################
*/

namespace BR
{
    /*
        Info
    */
    const char VERSION_SERVER[] = "Server version: 0.5.2";
    const char VERSION_CLIENT[] = "Client version: 0.1.7";
    const char VERSION_DATABASE[] = "sqlite3 version: 3270200";

    /*
        bd
    */
    const char DB_NAME[] = "test.db";

    /*
        Const
    */
    const char SERVER_IP[] = "127.0.0.1";
    const int  SERVER_PORT = 1234;

} // BR

/*
    ################################
    # UID
    ################################
*/

/*
    Куки пользователя
    id всегда одинаков
    Так как задан id, Coockie всегда уникалько и меняется после реконекта
*/
struct Coockie
{
    /* id пользователя */
    int id;

    /* Случайное число */
    unsigned int u_i_random;
};

/* Идентификатор пользователя */
struct UID
{
    /* Имя пользователя */
    std::string s_name;

    /* Куки пользователя */
    Coockie co_uid;
};

#endif // BATTLESHIPROYALE_H