#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	int number = 0;
	int rep = 0;
	char *s = mx_strdup(str);
	int j = 0;

	if ((!str) || (!sub) || (!replace))
        return NULL;
	for (int i = 0; i < mx_strlen(s); i++) {
		for (j=0; j < mx_strlen(sub); j++) {
			if((s[i]) == sub[j] && sub[j] != '\n') {
			i++;
			j++;
				if (j == mx_strlen(sub)) {
					number = j;
				}
			}
			else if(s[i] != sub[j]) 
				i++;
		}
	}
	number = j+1;
	while(rep <= mx_strlen(replace)) {
		s[number] = replace[rep];
		rep++;
		number++;
		j++;
	}	
	return s;
}

/*
int main() {
	char str[] = "McDonaldsalds";
	char sub[] = "alds";
	char replace[] = "utc";
	printf("%s\n", mx_replace_substr(str, sub, replace));
}
*/
