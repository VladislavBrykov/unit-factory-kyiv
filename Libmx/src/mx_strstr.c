#include "libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
    while (*s1 != '\0') {
        if (*s1 == *s2)
            if (!mx_strncmp(s1, s2, mx_strlen(s2)))
                return (char *)s1;
        s1++;
    }
    return NULL;
}
