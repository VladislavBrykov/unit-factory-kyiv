#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {  
    if (mx_strlen(needle) < 1)
        return (char*)haystack;
    for (int i = 0, j = 0, flag = 1; haystack[i] != '\0'; i++, j = 0, flag = 1) {
        if (haystack[i] == needle[j]) {
            while (needle[++j]) {
                if (needle[j] != haystack[i + j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                return (char*)&haystack[i];
        }
    }
    return NULL;
}

// int main() {
//     printf("%s\n", mx_strstr("Hello NEO! How are you?", "are"));
//     printf("%s\n", strstr("Hello NEO! How are you?", "are"));
//     return 0;
// }
