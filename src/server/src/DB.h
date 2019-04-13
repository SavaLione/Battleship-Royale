/**
 * @file
 * @brief Работа с базой данных
 * @author SavaLione
 * @date 13 Apr 2019
*/
/**
 * @defgroup dbh DB.h
 * @ingroup server
 * @{
*/
#ifndef DB_H
#define DB_H

#include <sqlite3.h>

#include "BattleshipRoyale.h"

/* Карточка пользователя */
struct db_player
{
    /* id */
    int id;

    /* Имя */
    std::string name;

    /* Пароль */
    std::string password;

    /* Дата регистрации */
    std::string reg_date;

    /* Очки */
    int score;

    /* Валюта */
    int money;

    /*
        Уровень доступа
            0   -   Пользователи
            1   -   Бета
            3   -   Админ
    */
    int level;
};

struct login
{
    std::string s_name;
    std::string s_password;
};

/**
 * @brief Подключение к базе данных
 */
class DB
{
private:
    /// База данных
    sqlite3 *db;

    /// Необходимо для получения данных из бд
    sqlite3_stmt *stmt;

    /// Сообщение о ошибке
    char *zErrMsg = new char;

    /// Ответ базы данных
    int *rc = new int;

    /// 
    int *id = new int;

    /// Сообщение о ошибке
    char *messageError;

    /**
     * @brief Открытие базы данных
     */
    void db_open();

    /**
     * @brief Закытие базы данных
     */
    void db_close();

    /**
     * @brief Создание базы данных
     */
    void db_create();

    /**
     * @brief Проверка существования таблицы Player
     */
    bool db_table_check();

    /**
     * @brief Вывод всех пользователей с информацией в консоль
     */
    void db_all_check();

    /**
     * @brief Вывод информации о пользователе по ссылке
     * @param [in] pl имя пользователя
     */
    void db_get_player_print(db_player *pl);

    /**
     * @brief Создание sha2 по ссылке
     * @param [in] s строка для преобразования в sha2
     * @return sha2 сообщение
     */
    std::string sha2(std::string *s);

public:
    /**
     * @brief Конструктор класса
     */
    DB();

    /**
     * @brief Создать пользователя l
     * @param [in] l пользователь
     */
    void db_add_player(login *l);

    /**
     * @brief Проверка существования пользователя
     * @param [in] s_name имя пользователя
     * @return true - пользователь существует, false - пользователь не существует.
     */
    bool db_check_player(std::string *s_name);

    /**
     * @brief Получить карточку пользователя db_player по ссылке
     * @param [in] name имя пользователя
     * @param [out] pl карточка пользователя
     */
    void db_get_player(std::string *name, db_player *pl);

    /**
     * @brief Получение id пользователя по имени. id уникальный
     * @param [in] s_name имя пользователя
     * @return id пользователя
     */
    int db_get_id(std::string *s_name);

    /**
     * @brief Проверка пароля
     * @param [in] l пользователь
     * @return true - пароль правильный, false - пароль не правильный.
     */
    bool db_check_pass(login *l);

    /**
     * @brief Получение UID пользователя
     * @param [in] l пользователь
     * @return UID
     */
    UID uid_get_np(login *l);

    /**
     * @brief Получение UID пользователя
     * @param [in] l пользователь
     * @param [in] id id
     * @return UID
     */
    UID uid_get_np(login *l, int *id);

    /**
     * @brief Получение даты регистрации по имени
     * @param [in] s_name имя пользователя
     * @return дата регистрации
     */
    std::string db_get_reg_date(std::string *s_name);

    /**
     * @brief Получение пароля по имени
     * @param [in] s_name имя пользователя
     * @return пароль (из бд. в sha2)
     */
    std::string db_get_password(std::string *s_name);

    /**
     * @brief Получение результата по имени
     * @param [in] s_name имя пользователя
     * @return результат(очки)
     */
    int db_get_score(std::string *s_name);

    /**
     * @brief Получение счёта по имени
     * @param [in] s_name имя пользователя
     * @return счёт
     */
    int db_get_money(std::string *s_name);

    /**
     * @brief Получение уровня доступа по имени
     * @param [in] s_name имя пользователя
     * @return уровень доступа
     */
    int db_get_level(std::string *s_name);

    /**
     * @brief Деструктор класса
     */
    ~DB();
};

#endif // DB_H
/** @} */