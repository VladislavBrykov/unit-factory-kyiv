#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
	char *s = (char *)src;
	char *d = (char *)dst;

	while(n > 0) {
		*d++ = *s++;
		n--;
	}
	return dst;
}

/*int main() {
	char *sourse = mx_strnew(5);
	sourse = "Hell";
	size_t num = 4;
	char *input = mx_strnew(num);
	mx_memcpy(input, sourse, num);
	printf("%s\n", input);
	return 0;
	
}
*/
