/**
 * @file
 * @brief Заголовочный файл с пространством имён, которое хранит в себе константы.
 * @author SavaLione
 * @date 13 Apr 2019
*/
/**
 * @defgroup battleship-royale Battleship-Royale
 * @brief Общие файлы
*/
/**
 * @defgroup server Server
 * @brief Сервер
*/
/**
 * @defgroup client Client
 * @brief Клиент
*/
/**
 * @defgroup battleshiproyale BattleShiproyale.h
 * @ingroup battleship-royale
 * @{
*/
#ifndef BATTLESHIPROYALE_H
#define BATTLESHIPROYALE_H

/**
 * @brief Пространство имён с константами
 * 
 * Version - Информация о версии
 * 
 * DB - База данных
 * 
 * Server - Константы сервера
 * 
 * Regex - регулярные выражения
*/
namespace BR
{
    ///////////////////////////////////////////////////////////////////////////////
    //      Version
    ///////////////////////////////////////////////////////////////////////////////

    /// Сервер. Major версия
    const int SERVER_VERSION_MAJOR = 0;

    /// Сервер. Minor версия
    const int SERVER_VERSION_MINOR = 2;

    /// Сервер. Path версия
    const int SERVER_VERSION_PATCH = 5;
    
    /// Клиент. Major версия
    const int CLIENT_VERSION_MAJOR = 0;

    /// Клиент. Minor версия
    const int CLIENT_VERSION_MINOR = 1;

    /// Клиент. Path версия
    const int CLIENT_VERSION_PATCH = 3;

    /// Версия Сервера
    const int SERVER_VERSION = (SERVER_VERSION_MAJOR * 10000 + SERVER_VERSION_MINOR * 100 + SERVER_VERSION_PATCH);

    /// Версия клиента
    const int CLIENT_VERSION = (CLIENT_VERSION_MAJOR * 10000 + CLIENT_VERSION_MINOR * 100 + CLIENT_VERSION_PATCH);

    ///////////////////////////////////////////////////////////////////////////////
    //      DB
    ///////////////////////////////////////////////////////////////////////////////

    /// Название базы данных
    const char DB_NAME[] = "test.db";

    /**
     * @brief Флаги sqlite3
     * 
     * PRAGMA synchronous = OFF; - Отключение синхронизации
     * 
     * PRAGMA encoding = "UTF-8"; - Использовать UTF-8
     * 
     * PRAGMA journal_mode = OFF; - Отключение журнала
     * 
     * Данные потеряются при аварийном завершении программы, при отключении питания и тд
     */
    const char SQLITE3_PRAGMA[] = "PRAGMA synchronous = OFF;"
                                  "PRAGMA encoding = \"UTF-8\";"
                                  "PRAGMA journal_mode = DELETE;";
    
    const char SQLITE3_TEST_DATA[] =
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES(1,                                'ZERO',      'ZEROZERO',       'ZERO',  1,    1,    1);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'SavaLione', 'MyOwOpass',      'now',   0,    0,    7);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'OwO',       'OwO',            '1234d', 0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'UwU',       'UwU',            'a',     0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Hewwwoo',   'Hiii',           'n',     0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Awwww',     'Awwwwwwwwwwwww', 'www',   1234, 1234, 0);";
    ///////////////////////////////////////////////////////////////////////////////
    //      Server
    ///////////////////////////////////////////////////////////////////////////////

    /// Стандартный адрес сервера
    const char SERVER_IP[] = "127.0.0.1";

    /// Стандартный порт сервера
    const int  SERVER_PORT = 1234;

    ///////////////////////////////////////////////////////////////////////////////
    //      Server
    ///////////////////////////////////////////////////////////////////////////////

    /// Регулярное выражение для поиска имени
    ///
    /// @code
    ///     user_check:[]
    /// @endcode
    const char REG_USER[] = "user_check:\\[([^\\[\\]]+)\\]";

    /// Регулярное выражение для поиска имени и пароля
    ///
    /// @code
    ///     user:[] pass:[]
    /// @endcode
    const char REG_USER_PASS[] = "user:\\[([^\\[\\]]+)\\] pass:\\[([^\\[\\]]+)\\]";

    /// Регулярное выражение для поиска уникального идентификатора и данных
    ///
    /// @code
    ///     UID:[] data:[]
    /// @endcode
    const char REG_UID[] = "UID:\\[([^\\[\\]]+)\\] data:\\[([^\\[\\]]+)\\]";

    /// Регулярное выражение для поиска ответа
    ///
    /// @code
    ///     answer:[true]
    /// @endcode
    const char REG_ANSWER_TRUE[] = "^answer:\\[true\\]$";

    /// Регулярное выражение для поиска ответа
    ///
    /// @code
    ///     answer:[false]
    /// @endcode
    const char REG_ANSWER_FALSE[] = "^answer:\\[false\\]$";

    /// Положительный ответ
    const char ANSWER_TRUE[] = "answer:[true]";

    /// Отрицательный ответ
    const char ANSWER_FALSE[] = "answer:[false]";

} // BR

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
/** @} */