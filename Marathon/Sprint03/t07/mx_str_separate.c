#include <unistd.h>

void mx_printchar(char c);

void mx_str_separate(const char *str, char delim) {
	char *s = (char *)str;
	while (*s) {
		if (*s == delim && *(s + 1) != delim)
			mx_printchar('\n');
		else
			mx_printchar(*s);
		s++; }
	mx_printchar('\n');
}
