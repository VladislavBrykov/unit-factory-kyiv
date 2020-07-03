#include "libmx.h"

char *mx_strtrim(const char *str) {
	char *new = mx_strdup(str);
	int i = 0;

	if(mx_strlen(str) == 0 || new == NULL)
		return NULL;
	while(((new[0] >= 9 && new[0] <= 13) || new[0] == 32)) {
		while(i <= mx_strlen(new)) {
			new[i] = new[i+1];
			i++;
		}
		i = 0;
	}
	while((new[mx_strlen(new) -1] >= 9 && new[mx_strlen(new) -1] <= 13) 
		|| new[mx_strlen(new) -1] == 32) {
		new[mx_strlen(new) - 1] = new[mx_strlen(new)];
	}
	if(mx_strlen(new) == 0)
		return NULL;
	return new;
}

/*
int main() {
	char name[] = "		ger ghjj ";
	printf("%s\n", mx_strtrim(name));
}
*/
