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

#include <ncursesw/curses.h>
#include <ncursesw/form.h>

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

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0); /* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
    wrefresh(local_win);  /* Show that box 		*/

    return local_win;
}

void destroy_win(WINDOW *local_win)
{
    /* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    /* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
    wrefresh(local_win);
    delwin(local_win);
}

void Window::testWindow()
{
    WINDOW *my_win = newwin(10, 10, 10, 10);
    int startx, starty, width, height;
    int ch;

    initscr();            /* Start curses mode 		*/
    cbreak();             /* Line buffering disabled, Pass on
					 * everty thing to me 		*/
    keypad(stdscr, TRUE); /* I need that nifty F1 	*/

    height = LINES / 2;
    width = COLS / 2;
    starty = 1; /* Calculating for a center placement */
    startx = 1; /* of the window		*/
    printw("Press F1 to exit");
    refresh();
    my_win = create_newwin(height, width, starty, startx);

    while ((ch = getch()) != KEY_F(1))
    {
        switch (ch)
        {
        case KEY_LEFT:
            destroy_win(my_win);
            my_win = create_newwin(height, width, starty, --startx);
            break;
        case KEY_RIGHT:
            destroy_win(my_win);
            my_win = create_newwin(height, width, starty, ++startx);
            break;
        case KEY_UP:
            destroy_win(my_win);
            my_win = create_newwin(height, width, --starty, startx);
            break;
        case KEY_DOWN:
            destroy_win(my_win);
            my_win = create_newwin(height, width, ++starty, startx);
            break;
        }
    }

    endwin();
}

void Window::newTest()
{
    initscr();

    addch('A' | A_BLINK);

    getch();
    endwin();
}

void Window::registration()
{
    WINDOW *my_win;
    int startx, starty, width, height;
    int ch;

    height = LINES;
    width = COLS;
    starty = 0;
    startx = 0;

    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    refresh();
    my_win = create_newwin(height, width, starty, startx);

    while ((ch = getch()) != KEY_F(1))
    {
        switch (ch)
        {
        case KEY_LEFT:
            destroy_win(my_win);
            my_win = create_newwin(height, width, starty, startx);
            break;
        case KEY_RIGHT:
            destroy_win(my_win);
            my_win = create_newwin(height, width, starty, startx);
            break;
        case KEY_UP:
            destroy_win(my_win);
            my_win = create_newwin(height, width, starty, startx);
            break;
        case KEY_DOWN:
            destroy_win(my_win);
            my_win = create_newwin(height, width, starty, startx);
            break;
        }
    }
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{
    int length, x, y;
    float temp;

    if (win == NULL)
        win = stdscr;
    getyx(win, y, x);
    if (startx != 0)
        x = startx;
    if (starty != 0)
        y = starty;
    if (width == 0)
        width = 80;

    length = strlen(string);
    temp = (width - length) / 2;
    x = startx + (int)temp;
    wattron(win, color);
    mvwprintw(win, y, x, "%s", string);
    wattroff(win, color);
    refresh();
}

void Window::testWin()
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

void Window::navigation()
{
    color_set(11, NULL);
    char nav[] = "USE [ARROWS] AND [TAB] TO NAVIGATE";
    mvwprintw(stdscr, LINES - 1, (COLS / 2) - (strlen(nav) / 2), nav);
    color_set(32, NULL);
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

/*
    for (std::string line; std::cout << BR::CONSOLE::GREETING && std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            BR::CONSOLE::process(line);
        }
    }
*/

/*
void Window::testWin()
{
    const int width = 50;
    const int height = 20;

    //initscr();
    curs_set(0);
    refresh();

    int offsetx = (COLS - width) / 2;
    int offsety = (LINES - height) / 2;

    WINDOW *win = newwin(height, width, offsety, offsetx);

    char hello[] = "Hello, world!";

    mvaddstr(LINES/2, (COLS-strlen(hello))/2, hello);
    box(win, 0, 0);

    wrefresh(win);
    getch();

    delwin(win);
    //endwin();
}
*/

// initscr();
// printw("Hello world!\n");
// refresh();
// getch();
// endwin();

/** @} */