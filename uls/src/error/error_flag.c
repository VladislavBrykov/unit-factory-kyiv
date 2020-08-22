#include "uls.h"

static char *del_first(char *argv) {
	int lon = mx_strlen(argv);
	char *new_name[lon-1];
	int j = 0;
	int i = 1;

	while(argv[i]) {
		new_name[j] = &argv[i];
		j++;
		i++;
	}
	return *new_name; //выдает флаг аргв без минуса
}

void error_flag(char *argv) {
	int i = 0;
	char *n_name = del_first(argv);
	char str_flags[37] = "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1";

	if(argv[0] == '-') {
		if(mx_strstr(str_flags, n_name) == NULL) { //если не находит строку в строке
		mx_printerr("uls: illegal option -- ");
		mx_printerr(n_name);
		mx_printerr("\n");
		mx_printerr("usage: uls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
		exit(1);
		}
	}
}
