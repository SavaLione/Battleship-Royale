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
                                  "PRAGMA journal_mode = OFF;";
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
    ///     user:[]
    /// @endcode
    const char REG_USER[] = "^user:\\[([^\\[\\]]+)\\]$";

    /// Регулярное выражение для поиска имени и пароля
    ///
    /// @code
    ///     user:[] pass:[]
    /// @endcode
    const char REG_USER_PASS[] = "^user:\\[([^\\[\\]]+)\\] pass:\\[([^\\[\\]]+)\\]$";

    /// Регулярное выражение для поиска уникального идентификатора и данных
    ///
    /// @code
    ///     UID:[] data:[]
    /// @endcode
    const char REG_UID[] = "^UID:\\[([^\\[\\]]+)\\] data:\\[([^\\[\\]]+)\\]$";

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