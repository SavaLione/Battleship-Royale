/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 30 Apr 2019
*/
/**
 * @defgroup tui_cpp TUI.cpp
 * @ingroup client
 * @{
 */
#include "TUI.h"

#include <string>
#include <cstring>

#include <vector>

#include <curses.h>

#include "BattleshipRoyale.h"

TUI::TUI()
{
    setlocale(LC_ALL, "");
    initscr();
    start_color();
    initColor();
}

TUI::~TUI()
{
    endwin();
}

void TUI::initColor()
{
    init_pair(BR::CODE::MENU::COLOR::BLACK_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(BR::CODE::MENU::COLOR::BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
    init_pair(BR::CODE::MENU::COLOR::GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
    init_pair(BR::CODE::MENU::COLOR::RED_BLACK, COLOR_RED, COLOR_BLACK);
    init_pair(BR::CODE::MENU::COLOR::YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);
    init_pair(BR::CODE::MENU::COLOR::MAGENTA_BLACK, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(BR::CODE::MENU::COLOR::CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);
    init_pair(BR::CODE::MENU::COLOR::WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);

    init_pair(BR::CODE::MENU::COLOR::BLACK_BLUE, COLOR_BLACK, COLOR_BLUE);
    init_pair(BR::CODE::MENU::COLOR::BLUE_BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(BR::CODE::MENU::COLOR::GREEN_BLUE, COLOR_GREEN, COLOR_BLUE);
    init_pair(BR::CODE::MENU::COLOR::RED_BLUE, COLOR_RED, COLOR_BLUE);
    init_pair(BR::CODE::MENU::COLOR::YELLOW_BLUE, COLOR_YELLOW, COLOR_BLUE);
    init_pair(BR::CODE::MENU::COLOR::MAGENTA_BLUE, COLOR_MAGENTA, COLOR_BLUE);
    init_pair(BR::CODE::MENU::COLOR::CYAN_BLUE, COLOR_CYAN, COLOR_BLUE);
    init_pair(BR::CODE::MENU::COLOR::WHITE_BLUE, COLOR_WHITE, COLOR_BLUE);

    init_pair(BR::CODE::MENU::COLOR::BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);
    init_pair(BR::CODE::MENU::COLOR::BLUE_GREEN, COLOR_BLUE, COLOR_GREEN);
    init_pair(BR::CODE::MENU::COLOR::GREEN_GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(BR::CODE::MENU::COLOR::RED_GREEN, COLOR_RED, COLOR_GREEN);
    init_pair(BR::CODE::MENU::COLOR::YELLOW_GREEN, COLOR_YELLOW, COLOR_GREEN);
    init_pair(BR::CODE::MENU::COLOR::MAGENTA_GREEN, COLOR_MAGENTA, COLOR_GREEN);
    init_pair(BR::CODE::MENU::COLOR::CYAN_GREEN, COLOR_CYAN, COLOR_GREEN);
    init_pair(BR::CODE::MENU::COLOR::WHITE_GREEN, COLOR_WHITE, COLOR_GREEN);

    init_pair(BR::CODE::MENU::COLOR::BLACK_RED, COLOR_BLACK, COLOR_RED);
    init_pair(BR::CODE::MENU::COLOR::BLUE_RED, COLOR_BLUE, COLOR_RED);
    init_pair(BR::CODE::MENU::COLOR::GREEN_RED, COLOR_GREEN, COLOR_RED);
    init_pair(BR::CODE::MENU::COLOR::RED_RED, COLOR_RED, COLOR_RED);
    init_pair(BR::CODE::MENU::COLOR::YELLOW_RED, COLOR_YELLOW, COLOR_RED);
    init_pair(BR::CODE::MENU::COLOR::MAGENTA_RED, COLOR_MAGENTA, COLOR_RED);
    init_pair(BR::CODE::MENU::COLOR::CYAN_RED, COLOR_CYAN, COLOR_RED);
    init_pair(BR::CODE::MENU::COLOR::WHITE_RED, COLOR_WHITE, COLOR_RED);

    init_pair(BR::CODE::MENU::COLOR::BLACK_YELLOW, COLOR_BLACK, COLOR_YELLOW);
    init_pair(BR::CODE::MENU::COLOR::BLUE_YELLOW, COLOR_BLUE, COLOR_YELLOW);
    init_pair(BR::CODE::MENU::COLOR::GREEN_YELLOW, COLOR_GREEN, COLOR_YELLOW);
    init_pair(BR::CODE::MENU::COLOR::RED_YELLOW, COLOR_RED, COLOR_YELLOW);
    init_pair(BR::CODE::MENU::COLOR::YELLOW_YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(BR::CODE::MENU::COLOR::MAGENTA_YELLOW, COLOR_MAGENTA, COLOR_YELLOW);
    init_pair(BR::CODE::MENU::COLOR::CYAN_YELLOW, COLOR_CYAN, COLOR_YELLOW);
    init_pair(BR::CODE::MENU::COLOR::WHITE_YELLOW, COLOR_WHITE, COLOR_YELLOW);

    init_pair(BR::CODE::MENU::COLOR::BLACK_MAGENTA, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(BR::CODE::MENU::COLOR::BLUE_MAGENTA, COLOR_BLUE, COLOR_MAGENTA);
    init_pair(BR::CODE::MENU::COLOR::GREEN_MAGENTA, COLOR_GREEN, COLOR_MAGENTA);
    init_pair(BR::CODE::MENU::COLOR::RED_MAGENTA, COLOR_RED, COLOR_MAGENTA);
    init_pair(BR::CODE::MENU::COLOR::YELLOW_MAGENTA, COLOR_YELLOW, COLOR_MAGENTA);
    init_pair(BR::CODE::MENU::COLOR::MAGENTA_MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(BR::CODE::MENU::COLOR::CYAN_MAGENTA, COLOR_CYAN, COLOR_MAGENTA);
    init_pair(BR::CODE::MENU::COLOR::WHITE_MAGENTA, COLOR_WHITE, COLOR_MAGENTA);

    init_pair(BR::CODE::MENU::COLOR::BLACK_CYAN, COLOR_BLACK, COLOR_CYAN);
    init_pair(BR::CODE::MENU::COLOR::BLUE_CYAN, COLOR_BLUE, COLOR_CYAN);
    init_pair(BR::CODE::MENU::COLOR::GREEN_CYAN, COLOR_GREEN, COLOR_CYAN);
    init_pair(BR::CODE::MENU::COLOR::RED_CYAN, COLOR_RED, COLOR_CYAN);
    init_pair(BR::CODE::MENU::COLOR::YELLOW_CYAN, COLOR_YELLOW, COLOR_CYAN);
    init_pair(BR::CODE::MENU::COLOR::MAGENTA_CYAN, COLOR_MAGENTA, COLOR_CYAN);
    init_pair(BR::CODE::MENU::COLOR::CYAN_CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(BR::CODE::MENU::COLOR::WHITE_CYAN, COLOR_WHITE, COLOR_CYAN);

    init_pair(BR::CODE::MENU::COLOR::BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
    init_pair(BR::CODE::MENU::COLOR::BLUE_WHITE, COLOR_BLUE, COLOR_WHITE);
    init_pair(BR::CODE::MENU::COLOR::GREEN_WHITE, COLOR_GREEN, COLOR_WHITE);
    init_pair(BR::CODE::MENU::COLOR::RED_WHITE, COLOR_RED, COLOR_WHITE);
    init_pair(BR::CODE::MENU::COLOR::YELLOW_WHITE, COLOR_YELLOW, COLOR_WHITE);
    init_pair(BR::CODE::MENU::COLOR::MAGENTA_WHITE, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(BR::CODE::MENU::COLOR::CYAN_WHITE, COLOR_CYAN, COLOR_WHITE);
    init_pair(BR::CODE::MENU::COLOR::WHITE_WHITE, COLOR_WHITE, COLOR_WHITE);

    init_pair(BR::CODE::MENU::COLOR::BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(BR::CODE::MENU::COLOR::BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(BR::CODE::MENU::COLOR::GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(BR::CODE::MENU::COLOR::RED, COLOR_RED, COLOR_RED);

    init_pair(BR::CODE::MENU::COLOR::YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(BR::CODE::MENU::COLOR::MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(BR::CODE::MENU::COLOR::CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(BR::CODE::MENU::COLOR::WHITE, COLOR_WHITE, COLOR_WHITE);
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

void TUI::move()
{
    WINDOW *my_win;
    int startx, starty, width, height;
    int ch;

    //initscr();            /* Start curses mode 		*/
    cbreak();             /* Line buffering disabled, Pass on
					 * everty thing to me 		*/
    keypad(stdscr, TRUE); /* I need that nifty F1 	*/

    height = 3;
    width = 10;
    starty = (LINES - height) / 2; /* Calculating for a center placement */
    startx = (COLS - width) / 2;   /* of the window		*/
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
}

void TUI::MainMenu()
{
    WINDOW *main_menu_win, *main_menu_top, *main_menu_bottom;

    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    clear();

    //bottom();
    refresh();

    bool fl_exit = false;

    std::vector<std::string> vec_menu_items;
    vec_menu_items.reserve(6);
    vec_menu_items.push_back("New game");
    vec_menu_items.push_back("Continue");
    vec_menu_items.push_back("Multiplayer");
    vec_menu_items.push_back("Settings");
    vec_menu_items.push_back("Help");
    vec_menu_items.push_back("Exit");

    std::vector<std::string>::size_type choice = 0;

    main_menu_top = newwin(7, COLS - 1, 0, 0);
    main_menu_win = newwin(LINES - 10, COLS - 1, 7, 0);
    main_menu_bottom = newwin(3, COLS - 1, LINES - 3, 0);

    box(main_menu_top, 0, 0);
    box(main_menu_win, 0, 0);
    box(main_menu_bottom, 0, 0);

    touchwin(main_menu_top);
    touchwin(main_menu_win);
    touchwin(main_menu_bottom);

    wrefresh(main_menu_top);
    wrefresh(main_menu_win);
    wrefresh(main_menu_bottom);

    while (!fl_exit)
    {
        int h = 0, w = 0;
        getmaxyx(main_menu_win, h, w);

        //wclear(main_menu_win);
        for (std::vector<std::string>::size_type i = 0; i < vec_menu_items.size(); i++)
        {
            if (i == choice)
            {
                wattron(main_menu_win, COLOR_PAIR(BR::CODE::MENU::COLOR::BLACK_WHITE));
                mvwprintw(main_menu_win, h / 2 + i, (w / 2) - (vec_menu_items[i].size() / 2), vec_menu_items[i].c_str());
                wattroff(main_menu_win, COLOR_PAIR(BR::CODE::MENU::COLOR::BLACK_WHITE));
            }
            else
            {
                wattron(main_menu_win, COLOR_PAIR(BR::CODE::MENU::COLOR::WHITE_BLACK));
                mvwprintw(main_menu_win, h / 2 + i, (w / 2) - (vec_menu_items[i].size() / 2), vec_menu_items[i].c_str());
                wattroff(main_menu_win, COLOR_PAIR(BR::CODE::MENU::COLOR::WHITE_BLACK));
            }
        }
        wrefresh(main_menu_top);
        wrefresh(main_menu_win);
        wrefresh(main_menu_bottom);

        switch (getch())
        {
        case KEY_UP:
            if (choice == 0)
            {
                choice = vec_menu_items.size() - 1;
            }
            else
            {
                choice--;
            }
            break;
        case KEY_DOWN:
            if (choice == vec_menu_items.size() - 1)
            {
                choice = 0;
            }
            else
            {
                choice++;
            }
            break;
        case KEY_LEFT:
            if (choice == 0)
            {
                choice = vec_menu_items.size() - 1;
            }
            else
            {
                choice--;
            }
            break;
        case KEY_RIGHT:
            if (choice == vec_menu_items.size() - 1)
            {
                choice = 0;
            }
            else
            {
                choice++;
            }
            break;
        case KEY_F(1):
            exit(0);
            break;

        default:
            break;
        }
    }
}

void TUI::bottom()
{
    color_set(BR::CODE::MENU::COLOR::WHITE_BLUE, NULL);
    mvprintw(LINES - 1, (COLS - 37) / 2, "USE ARROWS FOR NAVIGATION. F1 TO EXIT");
    color_set(BR::CODE::MENU::COLOR::WHITE_BLACK, NULL);
    refresh();
}

void TUI::colorTest()
{
    std::string msg = "A1!@#$%^&";
    int col = 0, line = 0;
    for (int i = 1; i <= BR::CODE::MENU::COLOR::WHITE; i++)
    {
        color_set(i, NULL);
        mvprintw(line, col * msg.length(), msg.c_str());
        col++;
        if (col > 3)
        {
            col = 0;
            line++;
        }
    }
    getch();
}

void TUI::locTest()
{
    std::string msg = "Привет! Тест локали!";
    mvprintw(1, 1, msg.c_str());
    getch();
}

/** @} */