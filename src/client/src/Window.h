/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 21 Apr 2019
*/
/**
 * @defgroup window_h Window.h
 * @ingroup client
 * @{
 */
#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#if _WIN32
#include <ncursesw/curses.h>
#include <ncursesw/form.h>
#elif __unix__
#include <ncurses/curses.h>
#include <ncurses/form.h>
#endif

#include <cstring>

class Window
{
private:
public:
    Window();
    ~Window();
    void testWindow();
    void newTest();
    void registration();
    void line();
    void testWin();
    void navigation();
    void color();
};

#endif // WINDOW_H
/** @} */