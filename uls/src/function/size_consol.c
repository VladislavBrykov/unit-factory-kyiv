#include "uls.h"

//текущая ширина консоли

int size_consol(void) {
	struct winsize window;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
	int size = window.ws_col;	
	//printf("%d\n", size);
return size;
}
