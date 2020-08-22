#include "libmx.h"

char *mx_strdup(const char *str) {
    char *dst = mx_strnew(mx_strlen(str)+1);
    mx_strcpy(dst, str);
    return dst;
}

// int main() {
//     char source[] = "Hello World";
//     char *target = mx_strdup(source);
//     printf("%s", target);
//     return 0;
// }
