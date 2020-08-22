#include "header.h"

int mx_strlen(const char *s) {
	int Length = 0;
	for (int i=0; s[i] != 0; i++) {
		Length++;
	}
	return Length;
}
