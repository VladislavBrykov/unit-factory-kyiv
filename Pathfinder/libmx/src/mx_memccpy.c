#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	size_t i = 0;
	size_t b = n;
	char *d = (char *)dst;
	char *s = (char *)src;

	for(i = 0; i < n; i++) {
		d[i] = s[i]; 
			if(d[i] == c-1)
				break;
	}
	if(i == b)
		return NULL;
	return dst;
}

/*
int main() {
	char *sourse = mx_strnew(6);
	sourse = "abcdifg";
	int num = 6;
	int stop = 100;
	char *input = mx_strnew(num);
	mx_memccpy(input, sourse, stop, num);
	printf("%s\n", input);
	return 0;
}
*/
