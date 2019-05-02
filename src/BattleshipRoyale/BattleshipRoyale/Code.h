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
        SUCCESSFULLY,
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

namespace MENU
{
namespace MAIN
{
    enum items
    {
        NEW_GAME = 1,
        CONTINUE,
        MULTIPLAYER,
        SETTINGS,
        HELP,
        EXIT,
        NOT_FOUND = 1024,
    };
}

namespace COLOR
{
    enum
    {
        BLACK_BLACK = 1,
        BLUE_BLACK,
        GREEN_BLACK,
        RED_BLACK,
        YELLOW_BLACK,
        MAGENTA_BLACK,
        CYAN_BLACK,
        WHITE_BLACK,

        BLACK_BLUE,
        BLUE_BLUE,
        GREEN_BLUE,
        RED_BLUE,
        YELLOW_BLUE,
        MAGENTA_BLUE,
        CYAN_BLUE,
        WHITE_BLUE,

        BLACK_GREEN,
        BLUE_GREEN,
        GREEN_GREEN,
        RED_GREEN,
        YELLOW_GREEN,
        MAGENTA_GREEN,
        CYAN_GREEN,
        WHITE_GREEN,

        BLACK_RED,
        BLUE_RED,
        GREEN_RED,
        RED_RED,
        YELLOW_RED,
        MAGENTA_RED,
        CYAN_RED,
        WHITE_RED,

        BLACK_YELLOW,
        BLUE_YELLOW,
        GREEN_YELLOW,
        RED_YELLOW,
        YELLOW_YELLOW,
        MAGENTA_YELLOW,
        CYAN_YELLOW,
        WHITE_YELLOW,

        BLACK_MAGENTA,
        BLUE_MAGENTA,
        GREEN_MAGENTA,
        RED_MAGENTA,
        YELLOW_MAGENTA,
        MAGENTA_MAGENTA,
        CYAN_MAGENTA,
        WHITE_MAGENTA,

        BLACK_CYAN,
        BLUE_CYAN,
        GREEN_CYAN,
        RED_CYAN,
        YELLOW_CYAN,
        MAGENTA_CYAN,
        CYAN_CYAN,
        WHITE_CYAN,

        BLACK_WHITE,
        BLUE_WHITE,
        GREEN_WHITE,
        RED_WHITE,
        YELLOW_WHITE,
        MAGENTA_WHITE,
        CYAN_WHITE,
        WHITE_WHITE,

        BLACK,
        BLUE,
        GREEN,
        RED,

        YELLOW,
        MAGENTA,
        CYAN,
        WHITE
    };
}
} // namespace MENU

} // namespace CODE
} // namespace BR


#endif // BR_CODE_H
/** @} */