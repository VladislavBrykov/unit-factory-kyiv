#include <stdio.h>
#include <unistd.h>

void mx_printchar(char c) {
	write(1, &c, 1);
}

int mx_strlen(const char *c) {
	int num = 0;
	while(c[num])
		num++;
	return num;
}

void mx_printstr(const char *s) {
	write(1, s, mx_strlen(s));
}

char *mx_strchr(const char *s, int c) {

	char *str = (char *) s;
	while(*str){
		if(*str == (char) c)
			return str;
		str++;
	}
	if(c == '\0')
		return str;
	return 0;
}

int main(int argc, char * argv[]) {
	argc = 1;
	char pointer;
	char stop;
	int i;
	for(i = 0; argv[0][i] != '\0'; i++) {
		if(argv[0][i] == '/') {
			pointer = argv[0][i+1];
			stop = i;
		}
	}
//shift argv[0] value to the right
	for(int a = 0; a <= stop; a++) {
		argv[0]++;
		
}
	char *a = mx_strchr(argv[0], pointer);
	mx_printstr(a);
	return 0;
}


