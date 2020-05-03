#include "minilibmx.h"


//int waiter;
 
					// Vremja mezhdu obnovlenijami strok v mikrosekundah.
					// Upravljaet skorost'ju jeffekta cifrovogo dozhdja

#define RAIN_LONG 40000 

					//Poluchit sluchajnoe celoe chislo v zadannom diapazone.
 
					//param int min Nizhnij predel diapazona.
					//param int max Verhnij predel diapazona.
 
					//return int Sluchajnoe celoe chislo

int get_rand_in_range(int min, int max)
{
	return (rand() % ((max + 1) - min) + min);
}
 
int main(void) {
					//Osnovnoe semja dlja sluchajnyh chisel.
	srand(time(NULL));
 
					//Nastrojte ekran ncurses i cveta..
	initscr();
	noecho(); 				//Vykljuchaem otobrazhenie vvodimyh simvolov
	curs_set(0);    			//Delaem kursor nevidimym
 
	start_color();
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE); 
	init_pair(1, COLOR_GREEN, COLOR_BLACK);  //Inicializacija cvetovyh par
//	init_pair(2, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
//	attron(A_BOLD | COLOR_PAIR(2)); 
  	int max_x = 0, max_y = 0;
 
  	getmaxyx(stdscr, max_y, max_x);
 
					//Sozdat massivy stolbcov na osnove shiriny ekrana
 
					//Massiv, soderzhashij tekushuyu stroku kazhdogo stolbca
  	int columns_row[max_x];
 
					//Massiv, soderzhashij aktivnoe sostoyanie kazhdogo stolbca.
					//Stolbec risuet simvoly v stroke, kogda aktiven.
 
  	int columns_active[max_x];
 
  	int i;
 
			//Ustanovit verhnyuyu stroku v kachestve tekushej stroki dlya vseh stolbcov
  	for (i = 0; i < max_x; i++) {
    		columns_row[i] = -1;
    		columns_active[i] = 0;
  		} 
 	nodelay(stdscr, TRUE);
	int q_ch = 1;
  	while (q_ch) {
        	if (getch() == 113) {
                q_ch = 0; 
		}
    	for (i = 0; i < max_x; i++) {
      		if (columns_row[i] == -1) {

					//Esli stolbec nahoditsya v verhnej stroke, vyberite
					//sluchajnyj startovyj ryad i aktivnyj status

        	columns_row[i] = get_rand_in_range(0, max_y);
        	columns_active[i] = get_rand_in_range(0, 1);
      		}
    	}
 
					//Prokruchivat stolbcy i risovat simvoly v strokah
    	for (i = 0; i < max_x; i++) {
      	if (columns_active[i] == 1) {
					//Narisujte sluchajnyj simvol v tekushej stroke etogo stolbca
       	int ascii_rand = get_rand_in_range(32, 126);
        mvprintw(columns_row[i], i, "%c", ascii_rand);
      	}
      	else {
					//Narisujte pustoj simvol, esli stolbec neaktiven
        mvprintw(columns_row[i], i, " ");
      	}
      	columns_row[i]++;
					//Kogda stolbec dostignet nizhnej stroki, 
						//vypolnite sbros na verhnyuyu.
      	if (columns_row[i] >= max_y) {
        	columns_row[i] = -1;
      	} 					//Sluchajno cheredovat aktivnyj status stolbca
      	if (get_rand_in_range(0, 1000) == 0) {
        	columns_active[i] = (columns_active[i] == 0) ? 1 : 0;
      		}
    	} 
  	usleep(RAIN_LONG);
   	refresh();	
  	} 
endwin();
return 0;
}
