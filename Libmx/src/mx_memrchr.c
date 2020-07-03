#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
	const char *sstr = (const char *)s ;
	size_t len = mx_strlen(sstr);

	while(*sstr && n > 0) {
		if(sstr[len] == c)
			return (void *)&sstr[len];
		len--;
		n--;
	}
	return NULL;
}

/*
int main() {
	char *str = "Hello";
	int c = 108;
	size_t n = 4;
	printf ("%s\n", mx_memchr(str, c, n));
	printf ("%s\n", str);

}
*/
