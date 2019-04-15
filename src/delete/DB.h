/**
 * @file
 * @brief Работа с базой данных
 * @deprecated
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

/**
 * @brief Подключение к базе данных
 */
class DB
{
private:
    /**
     * @brief База данных
     */
    sqlite3 *db;

    /**
     * @brief Необходимо для получения данных из бд
     */
    sqlite3_stmt *stmt;

    /**
     * @brief Сообщение о ошибке
     */
    char *zErrMsg = new char;

    /**
     * @brief Ответ базы данных
     */
    int *rc = new int;

    /// 
    int *id = new int;

    /**
     * @brief Сообщение о ошибке
     */
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

    /**
     * @brief Задать флаги sqlite3
     */
    void db_PRAGMA();

    std::string *s_sql = new std::string;

    //const char *cc_tale = new char;

public:
    /**
     * @brief Конструктор класса
     */
    DB();

    /**
     * @brief Проверка существования таблицы Player
     */
    void db_table_check();

    /**
     * @brief Проверка бд(получается открыть?)
     */
    void db_open_log();

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
     * @param [in] name имя пользователя
     * @param [in] pass пароль
     * @return true - пароль правильный, false - пароль не правильный.
     */
    bool db_check_pass(std::string *name, std::string *pass);

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
     * @brief Задать флаги sqlite3. Проверка возможности
     */
    void db_PRAGMA_log();
    
    /**
     * @brief Деструктор класса
     */
    ~DB();
};

#endif // DB_H
/** @} */