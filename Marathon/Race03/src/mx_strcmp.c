#include "header.h"

int mx_strcmp(const char *s1, const char *s2) {
	char *buf1 = (char*)s1;
	char *buf2 = (char*)s2;
	while(*buf1 != '\0' && *buf2 != '\0') {
		if (*buf1 != *buf2) return *buf1-*buf2;
		buf1++;
		buf2++;
	}
	if(*buf1 != '\0') return *buf1;
	if(*buf2 != '\0') return *buf2;
	return 0;
}
