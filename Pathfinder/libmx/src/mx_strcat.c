#include "libmx.h"

char *mx_strcat(char *s1, const char *s2) {
	int lenght1 = mx_strlen(s1);
	int i = 0;
	
	while(s2[i]) {
		s1[lenght1] = s2[i];
		lenght1++;
		i++;
	}
	s1[lenght1] = '\0';
	return s1;
}
