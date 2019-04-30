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

#include <string>
#include <cstring>

#include "curses.h"

Window::Window()
{
    initscr();
    start_color();
    color();
}

Window::~Window()
{
    endwin();
}

void Window::color()
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_BLUE, COLOR_WHITE);
    init_pair(8, COLOR_WHITE, COLOR_RED);
    init_pair(9, COLOR_BLACK, COLOR_GREEN);
    init_pair(10, COLOR_BLUE, COLOR_YELLOW);
    init_pair(11, COLOR_WHITE, COLOR_BLUE);
    init_pair(12, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(13, COLOR_BLACK, COLOR_CYAN);
    init_pair(32, COLOR_WHITE, COLOR_BLACK);
}

void Window::navigation()
{
    color_set(11, NULL);
    char nav[] = "USE [ARROWS] AND [TAB] TO NAVIGATE";
    mvwprintw(stdscr, LINES - 1, (COLS / 2) - (strlen(nav) / 2), nav);
    color_set(32, NULL);
}

void Window::testWindow()
{
    const int width = COLS;
    const int height = LINES - 1;

    //initscr();
    curs_set(0);
    refresh();

    //COLS
    //LINES

    int offsetx = 0;
    int offsety = 0;

    WINDOW *win = newwin(height, width, offsety, offsetx);

    char hello[] = "Hello, world!";

    mvaddstr(LINES / 2, (COLS - strlen(hello)) / 2, hello);
    box(win, 0, 0);

    navigation();

    wrefresh(win);
    refresh();
    getch();

    //delwin(win);
    endwin();
}

void Window::menu()
{
    
}

/** @} */