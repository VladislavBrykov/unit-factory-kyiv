#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *result = dst;
    const unsigned char *source = src;
    char *temp = mx_strnew(len);

    for (size_t i = 0; i < len; i++) 
        temp[i] = source[i]; 
    for (size_t i = 0; i < len; i++)
        result[i] = temp[i];
    free(temp);
    return dst;
}

// int main() {
//     char a[11] = "hello";
//     char *result = mx_memmove(a, &a[2], 3);
//     printf("%s\n", result);
// }

// int main() {
//     char a[10] = "hello";
//     char b[10];
//     char *result = mx_memmove(&b[2], a + 2, 5);
//     printf("%s\n", result);
// }
