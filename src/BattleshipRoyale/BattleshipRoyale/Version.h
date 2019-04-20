/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 20 Apr 2019
*/
/**
 * @defgroup version_h Version.h
 * @ingroup battleship-royale
 * @{
 */
#ifndef BR_VERSION_H
#define BR_VERSION_H

namespace BR
{
namespace VERSION
{

namespace SERVER
{
    /// Сервер. Major версия
    const int MAJOR = 0;

    /// Сервер. Minor версия
    const int MINOR = 2;

    /// Сервер. Path версия
    const int PATCH = 5;

    /// Версия Сервера
    const int VERSION = (MAJOR * 10000 + MINOR * 100 + PATCH);
} // namespace SERVER

namespace CLIENT
{
    /// Клиент. Major версия
    const int MAJOR = 0;

    /// Клиент. Minor версия
    const int MINOR = 1;

    /// Клиент. Path версия
    const int PATCH = 3;

    /// Версия клиента
    const int VERSION = (MAJOR * 10000 + MINOR * 100 + PATCH);

} // namespace CLIENT

} // namespace VERSION
} // namespace BR

#endif // BR_VERSION_H
/** @} */