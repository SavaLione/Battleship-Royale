#ifndef BATTLESHIPROYALE_H
#define BATTLESHIPROYALE_H

/*
    ################################
    # BR Константы
    ################################
*/

namespace BR
{
    /*
        Version
    */
    const int SERVER_VERSION_MAJOR = 0,
              SERVER_VERSION_MINOR = 2,
              SERVER_VERSION_PATCH = 5;
    
    const int CLIENT_VERSION_MAJOR = 0,
              CLIENT_VERSION_MINOR = 1,
              CLIENT_VERSION_PATCH = 3;

    const int SERVER_VERSION = (SERVER_VERSION_MAJOR * 10000 + SERVER_VERSION_MINOR * 100 + SERVER_VERSION_PATCH);
    const int CLIENT_VERSION = (CLIENT_VERSION_MAJOR * 10000 + CLIENT_VERSION_MINOR * 100 + CLIENT_VERSION_PATCH);

    /*
        bd
    */
    const char DB_NAME[] = "test.db";

    /*
        Const
    */
    const char SERVER_IP[] = "127.0.0.1";
    const int  SERVER_PORT = 1234;

    /*
        regex
    */

    /* user:[] */
    const char REG_USER[] = "^user:\\[([^\\[\\]]+)\\]$";

    /* user:[] pass:[] */
    const char REG_USER_PASS[] = "^user:\\[([^\\[\\]]+)\\] pass:\\[([^\\[\\]]+)\\]$";

    /* UID:[] data:[] */
    const char REG_UID[] = "^UID:\\[([^\\[\\]]+)\\] data:\\[([^\\[\\]]+)\\]$";

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

/*
    ################################
    # Some
    ################################
*/

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

#endif // BATTLESHIPROYALE_H