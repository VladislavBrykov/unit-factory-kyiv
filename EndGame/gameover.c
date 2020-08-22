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
        init_pair(3, COLOR_RED, COLOR_BLACK);
        init_pair(4, COLOR_BLACK, COLOR_CYAN);
	attrset(COLOR_PAIR(1));
	box(stdscr,'*','*'); 	
   	
curs_set(0);
attrset(COLOR_PAIR(2));
char robot[] = {
" $$$$   $$$$  $$   $ $$$$$"
};
len = strlen(robot);
    t = robot;           /* initialize pointer */
    while(len)
    {
        move(1,10);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(1);         /* .1 sec. delay */
        len--;
}
char robot1[] = {
"$$     $$  $$ $$$ $$ $$    "
};
len = strlen(robot);
    t = robot1;           /* initialize pointer */
    while(len)
    {
        move(2,10);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(1);         /* .1 sec. delay */
        len--;
}
char robot2[] = {
"$$ $$$ $$$$$$ $$ $ $ $$$$",
};
len = strlen(robot2);
    t = robot2;           /* initialize pointer */
    while(len)
    {
        move(3,10);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(1);         /* .1 sec. delay */
        len--;
}
char robot3[] = {
"$$  $$ $$  $$ $$   $ $$"
};
len = strlen(robot3);
    t = robot3;           /* initialize pointer */
    while(len)
    {
        move(4,10);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(1);         /* .1 sec. delay */
        len--;
}
char robot4[] = {
" $$$$  $$  $$ $$   $ $$$$$   "
};
len = strlen(robot4);
    t = robot4;           /* initialize pointer */
    while(len)
    {
        move(5,10);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(1);         /* .1 sec. delay */
        len--;
}
char robot5[] = {
" $$$$  $$  $$ $$$$$  $$$$$"
};
len = strlen(robot5);
    t = robot5;           /* initialize pointer */
    while(len)
    {
        move(10,30);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(1);         /* .1 sec. delay */
        len--;
}
char robot6[] = {
"$$  $$ $$  $$ $$     $$  $$"
};
len = strlen(robot6);
    t = robot6;           /* initialize pointer */
    while(len)
    {
        move(11,30);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(1);         /* .1 sec. delay */
        len--;
}
char robot7[] = {
"$$  $$ $$  $$ $$$$   $$$$$"
};
len = strlen(robot7);
    t = robot7;           /* initialize pointer */
    while(len)
    {
        move(12,30);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(1);         /* .1 sec. delay */
        len--;
}
char robot8[] = {
"$$  $$  $$$$  $$     $$  $$"
};
len = strlen(robot8);
    t = robot8;           /* initialize pointer */
    while(len)
    {
        move(13,30);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(1);         /* .1 sec. delay */
        len--;
}
char robot9[] = {
"  $$$$    $$   $$$$$  $$  $$"
};
len = strlen(robot9);
    t = robot9;           /* initialize pointer */
    while(len)
    {
        move(14,30);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(1);         /* .1 sec. delay */
        len--;
}
attrset(COLOR_PAIR(4));
char robot16[] = {
" LOSER UCODER "
};
len = strlen(robot16);
    t = robot16;           /* initialize pointer */
    while(len)
    {
        move(7,20);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
}

char robot17[] = {
" ORACLO WIN "
};
len = strlen(robot17);
    t = robot17;           /* initialize pointer */
    while(len)
    {
        move(17,30);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
}

attrset(COLOR_PAIR(3));
char robot10[] = {
"(''')./\\_/\\.(''')---"
};
len = strlen(robot10);
    t = robot10;           /* initialize pointer */
    while(len)
    {
        move(10,1);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
}
char robot11[] = {
"-\\..''.o_o.''../----"
};
len = strlen(robot11);
    t = robot11;           /* initialize pointer */
    while(len)
    {
        move(11,1);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
}
char robot12[] = {
"--\\..\\__W_/./-------"
};
len = strlen(robot12);
    t = robot12;           /* initialize pointer */
    while(len)
    {
        move(12,1);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
}
char robot13[] = {
"---|.........|------"
};
len = strlen(robot13);
    t = robot13;           /* initialize pointer */
    while(len)
    {
        move(13,1);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
}
char robot14[] = {
"---/.../U\\...\\-----"
};
len = strlen(robot14);
    t = robot14;           /* initialize pointer */
    while(len)
    {
        move(14,1);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
}
char robot15[] = {
"--(,,,)...(,,,)-----"
};
len = strlen(robot15);
    t = robot15;           /* initialize pointer */
    while(len)
    {
        move(15,1);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
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

