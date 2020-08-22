#include "mx_printerr.h"

int mx_strlen(const char *s) {
	int lenght = 0;
	for(int i = 0; s[i] != '\0'; i++) 
		lenght++;
	return lenght;
}

/*int main() {
	printf("%d\n", mx_strlen("12345"));
}*/
