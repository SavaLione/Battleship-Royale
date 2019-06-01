/**
 * @file
 * @brief Обработка команд в консоли сервера
 * @author SavaLione
 * @date 01 Jun 2019
 */
/**
 * @defgroup console_h Console.h
 * @ingroup server
 * @{
 */
#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <BattleshipRoyale.h>

namespace BR
{
namespace CONSOLE
{
    void process(std::string const& command);
    BR::CODE::CONSOLE::CMD getCommand(std::string const& command);
    void start();

} // namespace CONSOLE
} // namespace BR


#endif // CONSOLE_H
/** @} */