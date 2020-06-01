#include <stdio.h>
#include <unistd.h>

void mx_printchar(char c) {
	write(1, &c, 1);
}

void mx_printint(int i) {
	if(i < 0)
		mx_printchar('-');
	unsigned int num = i;
	if(num > 9)
		mx_printint(num / 10);
	mx_printchar(num % 10 + 48);
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

int main(int argc, char * argv[]) {
	mx_printstr(argv[0]);
	mx_printchar('\n');
	mx_printint(argc);
	mx_printchar('\n');
}


