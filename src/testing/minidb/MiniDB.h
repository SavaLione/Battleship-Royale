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
     * @brief Запрос
     * @code
     *      sqlite3 *db;
     *      *sql = "SELECT NAME FROM PLAYER;";
     *      request(db, sql);
     * @endcode
     * @param [in] db база данных
     * @param [in] request запрос
     */
    inline void request(sqlite3 *db, std::string *request)
    {
        sqlite3_exec(db, request->c_str(), NULL, NULL, NULL);
    }

    /**
     * @brief Запрос
     * @code
     *      sqlite3 *db;
     *      int rc;
     *      *sql = "SELECT NAME FROM PLAYER;";
     *      request(db, sql, &rc);
     * @endcode
     * @param [in] db база данных
     * @param [in] request запрос
     * @param [in] rc ответ
     */
    inline void request(sqlite3 *db, std::string *request, int *rc)
    {
        *rc = sqlite3_exec(db, request->c_str(), NULL, NULL, NULL);
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
};

#endif // MINIDB_H
/** @} */