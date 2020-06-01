#include <stdio.h>
#include <unistd.h>

void mx_printchar(char c) {
	write(1, &c, 1);
}

int mx_strlen(const char *s) {
	int num = 0;
	while(s[num])
		num++;
	return num;
}

void mx_printstr(const char *s) {
	write(1, s, mx_strlen(s));
}

int main(int argc, char *argv[])
{
	int num = 1;
	while (num < argc) {
		mx_printstr(argv[num]);
		mx_printchar('\n');
		num++;
	}
	return 0;
}

//clang -std=c11 -Wall -Wextra -Werror -Wpedantic
e2r7p9% ./test Hello Vlad good boy | cat -e 
