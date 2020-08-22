#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
	char *s = (char *)b;

	while(len > 0) {
		*s++ = c;
		len--;
	}	
	return b;

}

/*
int main() {
	char *z = mx_strnew(5);
	mx_memset(z, 97, 5);
	printf("%s\n", z);
	return 0;
}
*/
