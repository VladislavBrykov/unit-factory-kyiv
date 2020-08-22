#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
	if(s1 != NULL && s2 != NULL) {
		char *dubl_s1 = mx_strdup(s1);
		char *s1s2 = mx_strcat(dubl_s1, s2);
			return s1s2;
	}
	else if(s1 == NULL && s2 != NULL) {
		char *dubl_s2 = mx_strdup(s2);
			return dubl_s2;
	}
	else if(s2 == NULL && s1 != NULL) {
		char *dubl_s1 = mx_strdup(s1);
			return dubl_s1;
	}
	return NULL;
}
