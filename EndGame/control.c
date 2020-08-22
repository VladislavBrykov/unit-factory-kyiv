#include <ncurses.h>
#include <string.h>

void center(int row, char *title);
    
int main()
{   
 char *t;
    int len;   
    	initscr();
	    	start_color();
		if(!can_change_color())
        	addstr("You dont have color, Game Over...\n");	
	    	init_pair(1, COLOR_CYAN, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
	attrset(COLOR_PAIR(1));
	box(stdscr,'*','*'); 	
   	
		attrset(COLOR_PAIR(1));
    	center(5, "Orakl Run Control");
    	center(9, "Up - W");
    	center(11, " Right - A");
    	center(13, "Down - S");
	center(15, "Left - D");
	center(17, "Restart - R");

curs_set(0);
attrset(COLOR_PAIR(2));
char robot[] = "/\\_/\\(0-0RAKL0-0)/\\_/\\.....................\\(*o*)/";
len = strlen(robot);
    t = robot;           /* initialize pointer */
    while(len)
    {
        move(19,5);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(50);         /* .1 sec. delay */
        len--;

}
    getch();
    
    endwin();
    return(0);
}   

void center(int row, char *title)
{   
    int len,indent,y,width;
    getmaxyx(stdscr,y,width);
    len = strlen(title);
    indent = (width - len)/2;
    mvaddstr(row,indent,title);
    refresh();
}

