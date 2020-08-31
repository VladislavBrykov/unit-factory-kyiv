#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned int i = 0;
    const unsigned char *str1 = s1;
    const unsigned char *str2 = s2;
    for ( ; i < n; i++) {
        if (str1[i] != str2[i]) 
            return str1[i] - str2[i]; 
    }
    return 0;
}
// int main () {
//     char a[10] = "Hellb";
//     char b[10] = "Hella";
//     printf("%d\n", mx_memcmp(a, b, 5));
// }
