#include "header.h"
#include <time.h>
int random_1(int min, int max) {
  	return rand() % ((max - min) - 1) + min;
}
struct coord
{
   int x;
   int y;
};

struct PacMan {
   struct coord position;
   int vx;
   int vy;
   int lives;
   int speed;
   bool chasing;
   int food_collected;
};
struct PacMan myPacMan = {
                           {
                              .x = 2,
                              .y = 1,                              
                           },
                           .vx = 0,
                           .vy = 0,
                           .lives = 3,
			   .speed = 40000,
                           .chasing = false,
                           .food_collected = 0
                         };
char playfield[17][60] =
{
   { "############################################################" },
   { "##             ##############      ##                     ##" },
   { "## ###########                #### ## ## ################ ##" },
   { "## ##|UCODE|## ################### ## ##                  ##" },
   { "## ##.......##                     ## ############ ###### ##" },
   { "## ################# ############# ## ##           ##     ##" },
   { "##                                    ## ######### ## ### ##" },
   { "########################## #############        ## ## ### ##" },
   { "##                                    ######### ## ## ### ##" },
   { "## ############# ## ## ########## ### ##        ##    ### ##" },
   { "## ##            ## ## ##ORACL### ### ## ######### ## ### ##" },
   { "## ## ############# ## ##MAN##### ### ##        ## ## ### ##" },
   { "## ## ############# ## ########## ### ######### ## ## ### ##" },
   { "## ##               ## ######     ###           ## ## ### ##" },
   { "## ######### ######### ##     ####### ############ ##     ##" },
   { "##                        ###########                 ######" },
   { "############################################################" }
}; 
void user_input()
{
	int ch = getch();
     if (ch != ERR)
   	  {
         myPacMan.vx = 0;
         myPacMan.vy = 0;

         switch (ch)
         {
            case 'w': myPacMan.vy = -1; myPacMan.speed = 100000; break; // cursor up
            case 's': myPacMan.vy = +1; myPacMan.speed = 100000; break; // cursor down
            case 'a': myPacMan.vx = -1; myPacMan.speed = 60000; break;// cursor left
            case 'd': myPacMan.vx = +1; myPacMan.speed = 60000; break; // cursor right           
//		default: addch('R'); refresh(); break;
         }
      }     
   }
void move_figures()
{
   // 1. delete PacMan from old position
   mvaddch(myPacMan.position.y + 11, myPacMan.position.x + 60, ' ');
	
   // 2. compute new desired coordinate (nx,ny)
      int nx = myPacMan.vx + myPacMan.position.x;
      int ny = myPacMan.vy + myPacMan.position.y;

   // 3. test whether there is a wall at (nx,ny)  
      if (playfield[ny][nx] == '#')
   {
      // Damn! There is a wall! Stop PacMan!
        myPacMan.vx = 0;
        myPacMan.vy = 0;
     }

   // 4. update PacMan's coordinate
   myPacMan.position.x += myPacMan.vx;
   myPacMan.position.y += myPacMan.vy;

   // 5. is there a food piece at the new location?
    if (playfield[ny][nx] == '$')
     {
       myPacMan.food_collected++;
	playfield[ny][nx] = ' ';
     }

   // 6. put PacMan back again to playfield
   mvaddch(myPacMan.position.y + 11, myPacMan.position.x + 60, '@');   
}

int main() {
srand(time(0));
const int high = 17;
const int wigh = 60;
	keypad(stdscr, true);
	int y_rand, x_rand;
   	int count = 0;
	initscr();
	curs_set(0);
	noecho();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
//	attron(COLOR_PAIR(2));
	int rows;
        int columns;
        getmaxyx(stdscr, rows, columns);
	int y_centr = rows -(rows/2 + high/2);
	int x_centr = columns -(columns/2 + wigh/2);
	        while(count < 5) {
                y_rand = random_1(2, (high-2));
                x_rand = random_1(2, (wigh-2));
                if(playfield[y_rand][x_rand] == ' ') {
                        playfield[y_rand][x_rand] = '$';
                        count++;
                }
        }
	for(int i = 0; i < high; i++) {
		for(int j = 0; j < wigh; j++) {
			if(playfield[i][j] == '#'){
			attron(COLOR_PAIR(2) | A_BOLD);
			mvaddch(i + y_centr, j + x_centr, '#');
			}
			else {
			attron(COLOR_PAIR(1) | A_BOLD);
			mvaddch(i + y_centr, j + x_centr, playfield[i][j]);
			}
		}
	}
	attron(COLOR_PAIR(1) | A_BOLD);
	refresh();
	nodelay(stdscr, TRUE);
	
	while(1) {
		user_input();
      		move_figures();
		usleep(myPacMan.speed);
		mvprintw(y_centr + 18, x_centr, "You`ve got %d ucode coins", myPacMan.food_collected);
		if(myPacMan.food_collected == 5) {
			clear();
			refresh();
			mvprintw(y_rand, x_rand, "Congtats!!! Sprint is passed!!!\n Press any key to exit game...");
			nodelay(stdscr, FALSE);
			getch();
			break;
		}
	}
	clear();
	refresh();
	endwin();
}
