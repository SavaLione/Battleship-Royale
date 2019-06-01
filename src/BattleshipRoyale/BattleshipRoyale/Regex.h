/**
 * @file
 * @brief Константы регулярных выражений
 * @author SavaLione
 * @date 20 Apr 2019
*/
/**
 * @defgroup regex_h Regex.h
 * @ingroup battleship-royale
 * @{
 */
#ifndef BR_REGEX_H
#define BR_REGEX_H

namespace BR
{
namespace REGEX
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

namespace ANSWER
{
    /// Положительный ответ
    const char ANSWER_TRUE[] = "answer:[true]";

    /// Отрицательный ответ
    const char ANSWER_FALSE[] = "answer:[false]";

    /// Пользователь успешно создан
    const char SUCCESSFUL_USER_CREATED[] = "answer:[SUCCESSFUL_USER_CREATED]";

    /// Пользователь уже существует
    const char ERROR_USER_ALREADY_EXIST[] = "answer:[ERROR_USER_ALREADY_EXIST]";
} // namespace ANSWER

} // namespace REGEX
} // namespace BR

#endif // BR_REGEX_H
/** @} */