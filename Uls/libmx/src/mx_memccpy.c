#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned int i = 0;
    unsigned char symbol = c;
    unsigned char *result = dst;
    const unsigned char *source = src;

    while (i < n) {
        result[i] = source[i];
        if (result[i] == symbol)
            return (result+i+1);
        i++;
    }
    return NULL;
}

// int main() {
//     void *result = NULL; 
//     char a[10] = "hello";
//     char b[10];
//     result = mx_memccpy(b, a, 'l', 5);
// }
