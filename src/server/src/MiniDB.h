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
    int *rc = new int;

    /**
     * @brief База данных
     */
    sqlite3 *db;

    /**
     * @brief Необходимо для получения данных из бд
     */
    sqlite3_stmt *stmt;

    std::string *sql = new std::string;

    inline void request(std::string *request)
    {
        sqlite3_exec(db, request->c_str(), NULL, 0, NULL);
    }

public:
    MiniDB();
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
     * @param [out] пароль (из бд. в sha2)
     */
    void getPassword(std::string *name, std::string *sha2_ret);

    void setTable();
};

#endif // MINIDB_H