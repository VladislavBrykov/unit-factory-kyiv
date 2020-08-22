#include <stdio.h>

int mx_strlen(const char *s) {
	int file = 0;
	for (int a = 0; s[a] != 0; a++) {
		file++;
	}
	return(file);
}
