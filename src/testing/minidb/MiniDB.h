/**
 * @file
 * @brief Облегчённый класс для работы с бд
 * @author SavaLione
 * @date 14 Apr 2019
 */
/**
 * @defgroup minidb_h MiniDB.h
 * @ingroup server
 * @{
 */
#ifndef MINIDB_H
#define MINIDB_H

#include <string>

#include <sqlite3.h>

#include "BattleshipRoyale.h"

class MiniDB
{
private:
    /**
     * @brief Ответ базы данных
     */
    int rc;

    /**
     * @brief База данных
     */
    sqlite3 *db;

    /**
     * @brief Необходимо для получения данных из бд
     */
    sqlite3_stmt *stmt;

    /**
     * @brief Запрос
     */
    std::string sql;

    /**
     * @brief Запрос
     * @code
     *      *sql = "SELECT NAME FROM PLAYER;"
     *      request(sql);
     * @endcode
     * @param [in] request запрос
     */
    inline void request(std::string *request)
    {
        sqlite3_exec(db, request->c_str(), NULL, NULL, NULL);
    }

public:
    /**
     * @brief Конструктор класса
     */
    MiniDB();

    /**
     * @brief Деструктор класса
     */
    ~MiniDB();

    /**
     * @brief Проверка существования пользователя
     * @param [in] name имя пользователя
     * @return true - пользователь существует, false - пользователь не существует.
     */
    bool checkPlayer(std::string *name);

    /**
     * @brief Получение пароля по имени
     * @param [in] name имя пользователя
     * @param [out] sha2_ret пароль (из бд. в sha2)
     */
    void getPassword(std::string *name, std::string *sha2_ret);

    /**
     * @brief Инициализация базы данных
     */
    void setTable();

    void close();
};

#endif // MINIDB_H
/** @} */