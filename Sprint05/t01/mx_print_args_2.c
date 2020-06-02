#include <stdio.h>
#include <unistd.h>

void mx_printchar(char c) {
	write(1, &c, 1);
}

int mx_strlen(const char *s) {
	int i = 0;
	while(s[i])
		i++;
	return i;
}

void mx_printstr(const char *s) {
	write(1, s, mx_strlen(s));
}

int main(int argc, char *argv[]) {
	argc = 1;
	int i = 1;
	while(argv[i] != '\0') {
	mx_printstr(argv[i]);
	mx_printchar('\n');
	i++;
	}
}
