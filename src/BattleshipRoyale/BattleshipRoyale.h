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

    /// Название локальной базы данных
    const char SQLITE3_DB_LOCAL_NAME[] = "test.db";

    /// Название базы данных в памяти
    const char SQLITE3_DB_MEMORY_UID_NAME[] = "file:memdb1?mode=memory&cache=shared";

    /// Название базы данных в памяти
    const char SQLITE3_DB_MEMORY_MAP_NAME[] = "file:memdb2?mode=memory&cache=shared";

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
    const char SQLITE3_PRAGMA[] = 
        "PRAGMA synchronous = OFF;"
        "PRAGMA encoding = \"UTF-8\";"
        "PRAGMA journal_mode = DELETE;";
    
    /**
     * @brief Таблица локальной бд
     * @todo добавить поде для бана
     * @code
     *      |ID|NAME|PASSWORD|REG_DATE|SCORE|MONEY|LEVEL|
     * @endcode
     */
    const char SQLITE3_LOCAL_TABLE[] =
        "CREATE TABLE PLAYER("
            "ID INT PRIMARY KEY     NOT NULL, "
            "NAME           TEXT    NOT NULL, "
            "PASSWORD       TEXT    NOT NULL, "
            "REG_DATE       TEXT    NOT NULL, "
            "SCORE INT      KEY     NOT NULL, "
            "MONEY INT      KEY     NOT NULL, "
            "LEVEL INT      KEY     NOT NULL  "
        ");";
    
    /**
     * @brief таблица памяти map
     * @warning Нужно изменить
     * @todo Создать структуру бд для MAP
     * @code
     *      |ID|NAME|PASSWORD|REG_DATE|SCORE|MONEY|LEVEL|
     * @endcode
     */
    const char SQLITE3_DB_MEMORY_MAP_TABLE[] =
        "CREATE TABLE MAP("
            "ID INT PRIMARY KEY     NOT NULL, "
            "NAME           TEXT    NOT NULL, "
            "PASSWORD       TEXT    NOT NULL, "
            "REG_DATE       TEXT    NOT NULL, "
            "SCORE INT      KEY     NOT NULL, "
            "MONEY INT      KEY     NOT NULL, "
            "LEVEL INT      KEY     NOT NULL  "
        ");";

    /**
     * @brief таблица памяти uid
     * @code
     *      |ID|UID|NAME|
     * @endcode
     */
    const char SQLITE3_DB_MEMORY_UID_TABLE[] =
        "CREATE TABLE UID("
            "ID INT PRIMARY KEY     NOT NULL, "
            "UID            TEXT    NOT NULL, "
            "NAME           TEXT    NOT NULL  "
        ");";

    /**
     * @brief Тестовые данные uid
     * @todo Нужно создать запрет на вход SavaLione и OwO
     * @code
     *      |ID|         UID          |  NAME   |
     *      |--|----------------------|---------|
     *      |1 |SOME123STRONG456UID789|SavaLione|
     *      |2 |OWWO111OwO123OwO111OwO|OwO      |
     * @endcode
     */
    const char SQLITE3_DB_MEMORY_UID_DATA[] =
        "INSERT INTO UID (ID, UID, NAME) VALUES(1                               , 'SOME123STRONG456UID789', 'SavaLione');"
        "INSERT INTO UID (ID, UID, NAME) VALUES((SELECT max(ID) FROM UID) + 1   , 'OWWO111OwO123OwO111OwO', 'OwO'      );";
    
    /**
     * @brief Тестовые данные map
     * @todo Нужно создать запрет на вход SavaLione и OwO
     */
    const char SQLITE3_DB_MEMORY_MAP_DATA[] = "";

    /**
     * @brief Тестовые данные
     * @todo добавить поде для бана и запрет на вход
     * @code
     *      |ID|  NAME   |   PASSWORD   |REG_DATE|SCORE|MONEY|LEVEL|
     *      |--|---------|--------------|--------|-----|-----|-----|
     *      |1 |ZERO     |ZEROZERO      |ZERO    |1    |1    |1    |
     *      |2 |SavaLione|MyOwOpass     |now     |0    |0    |7    |
     *      |3 |OwO      |OwO           |1234d   |0    |0    |0    |
     *      |4 |UwU      |UwU           |a       |0    |0    |0    |
     *      |5 |Hewwwoo  |Hiii          |n       |0    |0    |0    |
     *      |6 |Awwww    |Awwwwwwwwwwwww|www     |1234 |1234 |0    |
     * @endcode
     */
    const char SQLITE3_LOCAL_DATA[] =
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES(1,                                'ZERO',      'ZEROZERO',       'ZERO',  1,    1,    1);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'SavaLione', 'MyOwOpass',      'now',   0,    0,    7);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'OwO',       'OwO',            '1234d', 0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'UwU',       'UwU',            'a',     0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Hewwwoo',   'Hiii',           'n',     0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Awwww',     'Awwwwwwwwwwwww', 'www',   1234, 1234, 0);";
    
    const int SQLITE3_MAX_MESSAGE_SIZE = 1024;

    const char SQLITE3_DB_MEMORY_UID_SECRET_CODE[] = "SOME";

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

    /// Регулярное выражение для создания пользователя
    ///
    /// @code
    ///     user:[] password:[]
    /// @endcode
    const char REG_USER_CREATE[] = "user:\\[([^\\[\\]]+)\\] password:\\[([^\\[\\]]+)\\]";

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

    /// Пользователь успешно создан
    const char ANSWER_SUCCESSFUL_USER_CREATED[] = "answer:[SUCCESSFUL_USER_CREATED]";

    /// Пользователь уже существует
    const char ANSWER_ERROR_USER_ALREADY_EXIST[] = "answer:[ERROR_USER_ALREADY_EXIST]";

} // BR

#endif // BATTLESHIPROYALE_H
/** @} */