#include <ncurses.h>

int main()
{
	initscr();
	printw("Run");
	refresh();
	getch();
	endwin();
	return 0;
}
