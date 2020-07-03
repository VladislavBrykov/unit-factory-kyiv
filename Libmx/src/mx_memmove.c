#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *result = (char *)dst;
    char *s = (char *)src;
    char *buf = NULL;
    buf = mx_strnew(len);

    if (len == 0)
        return NULL;
    mx_memcpy(buf, s, len);
    for (size_t i = 0; i < len; i++) {
        result[i] = buf[i];
    }
    free(buf);
    return dst;
}

/*
int main() {
	char d[] = "Hello";
	char s[] = "linux";
	printf("%s\n", mx_memmove(d, s, 7));
}
*/
