/**
 * @file
 * @brief handler
 * @author SavaLione
 * @date 14 Apr 2019
*/
/**
 * @defgroup con_handler_h con_handler.h
 * @ingroup server
 * @{
*/
#ifndef CON_HANDLER_H
#define CON_HANDLER_H

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "MiniDB.h"

/**
 * @brief Класс для общения
 */
class con_handler : public boost::enable_shared_from_this<con_handler>
{
private:
	/// Сокет
	boost::asio::ip::tcp::socket sock;

	/**
	 * @brief Сообщение, которое будет отправлено клиенту
	 */
	std::string answ;

	/**
	 * @brief Первый полученный параметр для обработки
	 */
	std::string s_param_one;

	/**
	 * @brief Второй полученный параметр для обработки
	 */
	std::string s_param_two;

	/**
	 * @brief Паттерн для проверки регулярного выражения
	 */
	std::string s_pattern_reg;

	/**
	 * @brief Полученный пароль в sha2
	 */
	std::string s_sha2;

	/// Максимальная длина сообщения
	enum
	{
		max_length = 1024
	};

	/// Данные, полученные от клиента
	char data[max_length];

	/**
	 * @brief Данные для проверки
	 */
	std::string data_check;

	/**
	 * @brief Работа с базой данных
	 */
	MiniDB mdb;

public:
	/**
	 * @brief Указатель но handler
	 */
	typedef boost::shared_ptr<con_handler> pointer;

	/**
     * @brief Конструктор класса
	 * 
	 * С списком инициализации
	 * 
	 * @param [in] io_service сервис
     */
	con_handler(boost::asio::io_service &io_service) : sock(io_service)
	{
		
	}

	/**
     * @brief Указатель на созданный сервис
     * @param [in] io_service сервис
     * @return указатель
     */
	static pointer create(boost::asio::io_service &io_service)
	{
		return pointer(new con_handler(io_service));
	}

	/**
	 * @brief Сокет
	 * @return Сокет
	 */
	boost::asio::ip::tcp::socket &socket();

	/**
	 * @brief Запуск handler
	 */
	void start();

	/**
     * @brief Чтение сообщения от клиента
     * @param [out] err ошибка
	 * @param [in] bytes_transferred 
     */
	void handle_read(const boost::system::error_code &err, size_t bytes_transferred);

	/**
     * @brief Отправка сообщения клиенту
     * @param [out] err ошибка
	 * @param [in] bytes_transferred 
     */
	void handle_write(const boost::system::error_code &err, size_t bytes_transferred);

	/**
	 * @brief обработка запроса. Поиск имени пользователя
	 * @param [in] request запрос
	 * @return true - запрос подходит(обработан), false - запрос не подходит(не обработан)
	 */
	bool processing_user_check(std::string const& request);

	/**
	 * @brief обработка запроса. Поиск имени и пароля
	 * @param [in] request запрос
	 * @return true - имя и пароль верны, false - имя и пароль не верны.
	 */
	bool processing_user_pass_check(std::string const& request);

	/**
     * @brief Деструктор класса
     */
	~con_handler();
};

#endif // CON_HANDLER_H
/** @} */