#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void  *src, size_t n) {
    unsigned int i = 0;
    unsigned char *result = dst;
    const unsigned char *source = src;
    
    while (i < n) {
        result[i] = source[i];
        i++;
    }
    return dst;
}

// int main() {
//     char a[10] = "hello";
//     char b[10];
//     char *result = mx_memcpy(b, a, 5);
//     printf("%s\n", result);
// }

// int main() {
//     char a[11] = "hello";
//     char *result = mx_memcpy(a, &a[2], 3);
//     printf("%s\n", result);
// }
