/**
 * @file
 * @brief Константы для работы с базой данных sqlite3
 * @author SavaLione
 * @date 20 Apr 2019
*/
/**
 * @defgroup sqlite3_h sqlite3.h
 * @ingroup battleship-royale
 * @{
 */
#ifndef BR_SQLITE3_H
#define BR_SQLITE3_H

namespace BR
{
namespace SQLITE3
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

namespace LOCAL
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
    
} // namespace LOCAL

namespace MEMORY
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
} // namespace MEMORY

} // namespace SQLITE3
} // namespace BR

#endif // BR_SQLITE3_H
/** @} */