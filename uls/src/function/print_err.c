#include "uls.h"

void print_err(char **ss) {
	int i = 1;
	while(ss[i] != NULL) {
		mx_printerr("uls: ");
		mx_printerr(ss[i]);
		mx_printerr(": No such file or directory");
		mx_printstr("\n");
		i++;
	}
}
