#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    char *str_join = NULL;
    int s1_len = 0;
    int s2_len = 0;

    if (!s1 && !s2) 
        return NULL;
    if (s1)
        s1_len = mx_strlen(s1);
    if (s2)
        s2_len = mx_strlen(s2);
    str_join = mx_strnew(s1_len + s2_len);
    if (s1)
        str_join = mx_strcpy(str_join, s1);
    if (s2) {
        str_join = mx_strcpy(&str_join[s1_len], s2);
        str_join -= s1_len;
    }
    return str_join;
}

// int main() {
//     char str1[] = "Hello ";
//     char str2[] = "world";
//     char *str3 = NULL;
//     printf("-%s\n\n", mx_strjoin(str1, str2));
//     printf("-%s\n", mx_strjoin(str1, str3));
//     return 0;
// }
