#include "libmx.h"

static bool mx_isspace(char c) {
	return ((c >= 9 && c <= 13) || (c == 32));
}

char *mx_del_extra_spaces(const char *str) {
	char *file = mx_strtrim(str);
	int i = 0;

	while(file[i] != '\0') {
		if (mx_isspace(file[i]) == 1 && mx_isspace(file[i+1]) == 1) {
			for(int f = i; (f+1) <= mx_strlen(file); f++)
				file[f] = file[f+1];
			i=0;
		}
		i++;
	}
	return file;
}

/*
int main() {
	char str[] = "\t Hello                      hello \t";
	printf("%s\n",mx_del_extra_spaces(str));
}
*/
