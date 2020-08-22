#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
	const char *sstr = (const char *)s ;
	size_t i = 0;

	while(*sstr && i < n) {
		if(*sstr == c)
			return (void *)sstr;
		i++;
		sstr++;
	}
	return NULL;
}

/*
int main() {
	char *str = "Hello";
	int c = 36;
	size_t n = 18;
	printf ("%s\n", mx_memchr(str, c, n));
	printf ("%s\n", str);

}
*/
