#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned int i = 0;
    unsigned char symbol = c;
    const unsigned char *source = s;

    while (i < n) {
        if (source[i] == symbol)
            return (void*)(source+i);
        i++;
    }
    return NULL;
}

// int main() {
//     void *result = NULL; 
//     char a[10] = "hello";
//     result = mx_memchr(a, 'l', 5);
// }
