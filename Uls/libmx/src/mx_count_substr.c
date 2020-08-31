#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;

    if (!str || !sub)
        return 0;
    for (int i = 0, j = 0, flag = 1; str[i] != '\0'; i++, j = 0, flag = 1) {
        if (str[i] == sub[j]) {
            while (sub[++j]) {
                if (sub[j] != str[i + j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                count++;
        }
    }
    return count;
}

// int main() {
//     char str[] = "yo, yo, yo Neo";
//     char sub[] = "yo";
//     //char sub[] = "Neo";
//     //char sub[] = "hi";
//     printf("%d\n", mx_count_substr(str, sub));
//     return 0;
// }
