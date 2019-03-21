#include <curses.h>

#include <stdio.h>

int main()
{
	initscr();
	mvprintw( 5, 5, "Run 5,5 " );
	endwin();
	return 0;
}
