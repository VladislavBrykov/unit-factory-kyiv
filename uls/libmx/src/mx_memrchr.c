#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char symbol = c;
    const unsigned char *source = s;

    while (n >= 0) {
        if (source[n] == symbol)
            return (void*)(source+n);
        n--;
    }
    return NULL;
}

// int main() {
//     void *result = NULL; 
//     char a[10] = "hello";
//     result = mx_memrchr(a, 'l', 5);
// }
