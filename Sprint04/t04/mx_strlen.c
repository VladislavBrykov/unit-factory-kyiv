#include <stdio.h>

int mx_strlen(const char *s) {
	int l = 0;
	for (int i=0;s[i]!=0;i++) {
		l++;
		}
	return(l);
}
