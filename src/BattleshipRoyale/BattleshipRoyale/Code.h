/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 20 Apr 2019
*/
/**
 * @defgroup code_h Code.h
 * @ingroup battleship-royale
 * @{
 */
#ifndef BR_CODE_H
#define BR_CODE_H

namespace BR
{
namespace CODE
{

namespace CONNECTION
{
    enum conn
    {
        OK,
        NICKNAME_ALREADY_EXIST,
        NICKNAME_FREE,
        PASSWORD_WRONG,
        PASSWORD_CORRECT
    };
} // namespace CONNECTION

namespace CONSOLE
{
    enum CMD
    {
        HELP,
        EXIT,
        SHUTDOWN,
        RESET,
        NOT_FOUND = 1024
    };
} // namespace CONSOLE


} // namespace CODE
} // namespace BR


#endif // BR_CODE_H
/** @} */