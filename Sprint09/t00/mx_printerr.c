#include "printerr.h"

void mx_printerr(const char *s) {
	for (int i = 0; i < mx_strlen(s); i++) {
		write(2,&s[i],1);
		}
		//char a = '\n';
		//write(1,&a,1);
}

// int main() {
//	mx_printerr("fgjfyjgk"); 
// }
