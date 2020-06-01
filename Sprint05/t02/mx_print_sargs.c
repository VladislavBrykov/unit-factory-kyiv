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

int mx_strcmp(const char *s1, const char *s2) {
	int i = 0;
	while(s1[i]) { 
		if(s1[i] != s2[i])
		return(s1[i] - s2[i]);
		i++;
		}
	return 0;
}

int main(int argc, char *argv[]) {

	for(int i = 1; i < argc; i++) {
		for(int j = 1; j < argc-i; j++) {
			if(mx_strcmp(argv[j], argv[j+1]) > 0){
				char *papka = argv[j];
				argv[j] = argv[j+1];
				argv[j+1] = papka;
			}
		}
	}

	for(int i = 1; i < argc; i++){
		mx_printstr(argv[i]);
		mx_printchar('\n');
	}

	return 0;
}
