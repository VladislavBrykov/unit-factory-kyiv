#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;
    int j = mx_strlen(src);

    if (!dst || !src) 
        return dst;
    while (i < len) {
       if (i < j) {
           dst[i] = src[i];
        } 
        else
           dst[i] = '\0'; 
        i++;
    }
    return dst;
}

// int main() {
//     char arr[6];
//     printf("%s", mx_strncpy(arr, "abcsdffsss", sizeof(arr)));
//     return 0;
// }
