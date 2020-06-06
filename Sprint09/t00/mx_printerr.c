#include "mx_printerr.h"

void mx_printerr(const char *s) {
for(int i = 0; i <= mx_strlen(s); i++) {
	write(2, &s[i], 1);
	}
}

int main() {
	mx_printerr("123456789");
}
