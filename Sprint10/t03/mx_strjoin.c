#include "file_to_str.h"

int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 == 0 || s2 == 0) {
        return 0;
    }
    int l1 = mx_strlen(s1);
    int l2 = mx_strlen(s2);
    char *result = mx_strnew(l1 + l2);
    if (result == 0) {
        return 0;
    }
    mx_strcpy(result, s1);
    mx_strcpy(result + l1, s2);
    return result;
}

int main() {
        char arr1[] = "hello";
        char arr2[] = "world";
        printf("%s",mx_strjoin(arr1, arr2));
}

