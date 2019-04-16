/**
 * @file
 * @brief Обработка запросов
 * @author SavaLione
 * @date 16 Apr 2019
*/
/**
 * @defgroup processing_h Processing.h
 * @ingroup server
 * @{
*/
#ifndef PROCESSING_H
#define PROCESSING_H

#include "MiniDB.h"

class Processing
{
private:
    enum REQ
    {
        USER_CHECK,
        USER_PASS_CHECK,
        USER_UID,
        USER_CREATE,
        REQ_ERROR = 1024
    };

	/**
	 * @brief Работа с базой данных
	 */
    MiniDB mdb;

    REQ getREQ(std::string const& request);

public:
    /**
     * @brief Конструктор класса
     */
    Processing();

    /**
     * @brief Деструктор класса
     */
    ~Processing();

    /**
     * @brief Запрос
     * @param [in] request строка с запросом
     * @return Ответ
     */
    std::string response(std::string const& request);
};

#endif // PROCESSING_H
/** @} */