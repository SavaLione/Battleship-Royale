/**
 * @file
 * @brief Облегчённый класс для работы с бд
 * @example MiniDB.cpp
 * @author SavaLione
 * @date 15 Apr 2019
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

/**
 * @brief Компактная база данных
 */
class MiniDB
{
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
    bool checkPlayer(std::string const& name);

    /**
     * @brief Получение пароля по имени
     * @param [in] name имя пользователя
     * @param [out] sha2_ret пароль (из бд. в sha2)
     */
    void getPassword(std::string const& name, std::string& sha2_ret);

    /**
     * @brief Инициализация базы данных
     */
    void setTable();

    /**
     * @brief Создание пользователя
     * @param [in] name имя пользователя
     * @param [in] sha2 пароль (из бд. в sha2)
     */
    void createPlayer(std::string const& name, std::string const& sha2);
};

#endif // MINIDB_H
/** @} */