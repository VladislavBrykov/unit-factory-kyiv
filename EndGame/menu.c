#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <menu.h>
#include <stdlib.h>           // added for exit() function

void fail(char *msg) {
    endwin();
    puts(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    /* Commandline argument currently unused */
    (void) argc;
    (void) argv;

    int i, c;
    (void) c;                       // c is currently unused
    int szer, dlug;

    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    if (has_colors() == false) {
        fail("Colors unavailable\n");
    }

    if (start_color() != OK) {
        fail("Unable to start colors\n");
    }

    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    getmaxyx(stdscr, szer, dlug);
//    move(szer/2, (dlug-strlen(powitanie))/2); 
//    attron(COLOR_PAIR(1));
//    printw(powitanie);
//    attroff(COLOR_PAIR(1));
    refresh();
    WINDOW * menuwin=newwin(7, dlug-12, szer-9, 6);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, TRUE);
	curs_set(0);	

    char *opcje[] = {
        "Start",
        "About",
        "Control",
	"Developers",
        "Exit",
};
int wybor;
    int zaznacz=0;
    while(1)//cala ta petla sluzy ciaglemu tworzeniu menu z podswietleniem wybranego elementu
    {
        for(i = 0; i < 5; i++) {
            if(i == zaznacz)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, opcje[i]);
            if (i == zaznacz)
                wattroff(menuwin, A_REVERSE);
        }

        wybor = wgetch(menuwin);
        switch(wybor)
        {





        case KEY_UP:
            zaznacz--;
            if(zaznacz < 0) zaznacz = 0;//zabezpieczenie przed wyjsciem "poza" menu
            break;
        case KEY_DOWN:
            zaznacz++;
            if(zaznacz > 4) zaznacz = 4;
            break;
        default:
            break;
        }

        if(wybor==10) break;
    }
    refresh();

    /* Wait for user to press enter to exit */
    getch();

    /* Need to cleanup before exit */
    endwin();

    return 0;
}
