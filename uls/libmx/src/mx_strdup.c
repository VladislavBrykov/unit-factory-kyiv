#include "libmx.h"

char *mx_strdup(const char *s1) {
    char *dup = mx_strnew(mx_strlen(s1));
    int i = 0;

    if (!dup)
        return NULL;
    while (s1[i] != '\0') {
        dup[i] = s1[i];
        i++;
    }
    return dup;
}

// int main () {
//     char string[] = {"Hello world!"};
//     char *dup = mx_strdup(string);
//     printf("%s\n", dup);
//     free(dup);
//     return 0;
// }
