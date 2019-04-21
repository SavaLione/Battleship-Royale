/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 21 Apr 2019
*/
/**
 * @defgroup window_cpp Window.cpp
 * @ingroup client
 * @{
 */
#include "Window.h"

#include <ncursesw/curses.h>

Window::Window()
{
    initscr();
    printw("Hello world!\n");
    refresh();
    getch();
    endwin();
}

Window::~Window()
{
}

/** @} */