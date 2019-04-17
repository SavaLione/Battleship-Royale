#include <ncursesw/ncurses.h>

int main()
{
    initscr();
    mvprintw( 5, 5, "Hello, World!" );
    getch();
    endwin();
    return 0;
}