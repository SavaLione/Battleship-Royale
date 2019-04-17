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

} // BR

namespace BR::REGEX
{
    /// Регулярное выражение для поиска имени
    ///
    /// @code
    ///     user_check:[]
    /// @endcode
    const char USER[] = "user_check:\\[([^\\[\\]]+)\\]";

    /// Регулярное выражение для поиска имени и пароля
    ///
    /// @code
    ///     user:[] pass:[]
    /// @endcode
    const char USER_PASS[] = "user:\\[([^\\[\\]]+)\\] pass:\\[([^\\[\\]]+)\\]";

    /// Регулярное выражение для поиска уникального идентификатора и данных
    ///
    /// @code
    ///     UID:[] data:[]
    /// @endcode
    const char UID[] = "UID:\\[([^\\[\\]]+)\\] data:\\[([^\\[\\]]+)\\]";

    /// Регулярное выражение для создания пользователя
    ///
    /// @code
    ///     user:[] password:[]
    /// @endcode
    const char USER_CREATE[] = "user:\\[([^\\[\\]]+)\\] password:\\[([^\\[\\]]+)\\]";

    /// Регулярное выражение для поиска ответа
    ///
    /// @code
    ///     answer:[true]
    /// @endcode
    const char ANSWER_TRUE[] = "^answer:\\[true\\]$";

    /// Регулярное выражение для поиска ответа
    ///
    /// @code
    ///     answer:[false]
    /// @endcode
    const char ANSWER_FALSE[] = "^answer:\\[false\\]$";

} // namespace BR::REGEX

namespace BR::REGEX::ANSWER
{
    /// Положительный ответ
    const char ANSWER_TRUE[] = "answer:[true]";

    /// Отрицательный ответ
    const char ANSWER_FALSE[] = "answer:[false]";

    /// Пользователь успешно создан
    const char SUCCESSFUL_USER_CREATED[] = "answer:[SUCCESSFUL_USER_CREATED]";

    /// Пользователь уже существует
    const char ERROR_USER_ALREADY_EXIST[] = "answer:[ERROR_USER_ALREADY_EXIST]";
} // namespace BR::REGEX::ANSWER


namespace BR::CONNECT
{
    /// Стандартный адрес сервера
    const char IP[] = "127.0.0.1";

    /// Стандартный порт сервера
    const int  PORT = 1234;
} // namespace BR::CONNECT


/**
 * @brief Версия
 */
namespace BR::VERSION
{
    /// Версия Сервера
    const int server = (BR::VERSION::SERVER::MAJOR * 10000 + BR::VERSION::SERVER::MINOR * 100 + BR::VERSION::SERVER::PATCH);

    /// Версия клиента
    const int client = (BR::VERSION::CLIENT::MAJOR * 10000 + BR::VERSION::CLIENT::MINOR * 100 + BR::VERSION::CLIENT::PATCH);

} // namespace BR::VERSION

namespace BR::VERSION::SERVER
{
    /// Сервер. Major версия
    const int MAJOR = 0;

    /// Сервер. Minor версия
    const int MINOR = 2;

    /// Сервер. Path версия
    const int PATCH = 5;
} // namespace BR::VERSION::SERVER

namespace BR::VERSION::CLIENT
{
    /// Клиент. Major версия
    const int MAJOR = 0;

    /// Клиент. Minor версия
    const int MINOR = 1;

    /// Клиент. Path версия
    const int PATCH = 3;
} // namespace BR::VERSION::CLIENT

/**
 * @brief Работа с базой данных
 */
namespace BR::SQLITE3
{
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
    const char PRAGMA[] = 
        "PRAGMA synchronous = OFF;"
        "PRAGMA encoding = \"UTF-8\";"
        "PRAGMA journal_mode = DELETE;";
    
    const int MAX_MESSAGE_SIZE = 1024;

} // namespace BR::SQLITE3

namespace BR::SQLITE3::LOCAL
{
    /// Название локальной базы данных
    const char NAME[] = "test.db";

    /**
     * @brief Таблица локальной бд
     * @todo добавить поде для бана
     * @code
     *      |ID|NAME|PASSWORD|REG_DATE|SCORE|MONEY|LEVEL|
     * @endcode
     */
    const char TABLE[] =
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
    const char DATA[] =
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES(1,                                'ZERO',      'ZEROZERO',       'ZERO',  1,    1,    1);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'SavaLione', 'MyOwOpass',      'now',   0,    0,    7);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'OwO',       'OwO',            '1234d', 0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'UwU',       'UwU',            'a',     0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Hewwwoo',   'Hiii',           'n',     0,    0,    0);"
        "INSERT INTO PLAYER (ID, NAME, PASSWORD, REG_DATE, SCORE, MONEY, LEVEL) VALUES((SELECT max(ID) FROM PLAYER) + 1, 'Awwww',     'Awwwwwwwwwwwww', 'www',   1234, 1234, 0);";
    
} // namespace BR::SQLITE3::LOCAL

namespace BR::SQLITE3::MEMORY
{
    /// Название базы данных uid в памяти
    const char UID[] = "file:memdb1?mode=memory&cache=shared";

    /// Код для генерации sha2
    const char UID_SECRET_CODE[] = "SOME";

    /// Название базы данных map в памяти
    const char MAP[] = "file:memdb2?mode=memory&cache=shared";

    /**
     * @brief таблица памяти map
     * @warning Нужно изменить
     * @todo Создать структуру бд для MAP
     * @code
     *      |ID|NAME|PASSWORD|REG_DATE|SCORE|MONEY|LEVEL|
     * @endcode
     */
    const char TABLE_MAP[] =
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
    const char TABLE_UID[] =
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
    const char DATA_UID[] =
        "INSERT INTO UID (ID, UID, NAME) VALUES(1                               , 'SOME123STRONG456UID789', 'SavaLione');"
        "INSERT INTO UID (ID, UID, NAME) VALUES((SELECT max(ID) FROM UID) + 1   , 'OWWO111OwO123OwO111OwO', 'OwO'      );";
    
    /**
     * @brief Тестовые данные map
     * @todo Нужно создать запрет на вход SavaLione и OwO
     */
    const char DATA_MAP[] = "";
} // namespace BR::SQLITE3::MEMORY


/**
 * @brief Работа с консолью сервера
 */
namespace BR::CONSOLE
{
    ///////////////////////////////////////////////////////////////////////////////
    //      Console
    ///////////////////////////////////////////////////////////////////////////////

    /// Консоль
    ///
    /// @code
    ///     BR > 
    /// @endcode
    const char GREETING[] = "BR > ";

    /// Помощь по командам
    /// @code
    ///     help        h   -   Help Commands
    ///     exit        e   -   Exit from the program (soft)
    ///     shutdown    s   -   Exit from the program (hard)
    ///     reset       r   -   Reset database in memory
    /// @endcode
    const char HELP[] = 
        "\t"    "help        h   -   Help Commands"                     "\n"
        "\t"    "exit        e   -   Exit from the program (soft)"      "\n"
        "\t"    "shutdown    s   -   Exit from the program (hard)"      "\n"
        "\t"    "reset       r   -   Reset database in memory"          "\n";

    /// Сообщение о том, что команда не найдена
    const char NOT_FOUND[] = "Command not found.\nTry using: help";

} // namespace BR::CONSOLE

/**
 * @brief Команды в консоли сервера
 */
namespace BR::CONSOLE::COMMANDS
{
    const char HELP[] = "help";
    const char HELP_SHORT[] = "h";

    const char EXIT[] = "exit";
    const char EXIT_SHORT[] = "e";

    const char SHUTDOWN[] = "shutdown";
    const char SHUTDOWN_SHORT[] = "s";

    const char RESET[] = "reset";
    const char RESET_SHORT[] = "r";
} // namespace BR::CONSOLE::HELP


#endif // BATTLESHIPROYALE_H
/** @} */