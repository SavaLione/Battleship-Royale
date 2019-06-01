/**
 * @file
 * @brief Константы консоли
 * @author SavaLione
 * @date 20 Apr 2019
*/
/**
 * @defgroup console_h Console.h
 * @ingroup battleship-royale
 * @{
 */
#ifndef BR_CONSOLE_H
#define BR_CONSOLE_H

namespace BR
{
namespace CONSOLE
{
    ///////////////////////////////////////////////////////////////////////////////
    //      Console
    ///////////////////////////////////////////////////////////////////////////////

    /// Консоль
    ///
    /// @code
    ///     BR > 
    /// @endcode
    const char GREETING[] = "BR > ";

namespace MESSAGE
{
    /// Помощь по командам
    /// @code
    ///     help        h   -   Help Commands
    ///     exit        e   -   Exit from the program (soft)
    ///     shutdown    s   -   Exit from the program (hard)
    ///     reset       r   -   Reset database in memory
    /// @endcode
    const char HELP[] = 
        "\t"    "help        h   -   Help Commands"                     "\n"
        "\t"    "exit        e   -   Exit from the program (soft)"      "\n"
        "\t"    "shutdown    s   -   Exit from the program (hard)"      "\n"
        "\t"    "reset       r   -   Reset database in memory"          "\n";
    
    /// Сообщение о том, что команда не найдена
    const char NOT_FOUND[] = "Command not found.\nTry using: help";
} // namespace MESSAGE    

namespace COMMANDS
{
    const char HELP[] = "help";
    const char HELP_SHORT[] = "h";

    const char EXIT[] = "exit";
    const char EXIT_SHORT[] = "e";

    const char SHUTDOWN[] = "shutdown";
    const char SHUTDOWN_SHORT[] = "s";

    const char RESET[] = "reset";
    const char RESET_SHORT[] = "r";
} // namespace COMMANDS

} // namespace CONSOLE
} // namespace BR

#endif // BR_CONSOLE_H
/** @} */