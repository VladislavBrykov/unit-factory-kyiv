#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int count = 0;
    int len = mx_strlen(str);

    if (!str || !c) 
        return -1;
    for (int i = 0; i < len; i++)
        if (str[i] == c && str[i + 1] != c)
            count++;
    if (str[0] == c)
        count--;
    if (str[len - 1] == c) 
        count--;
    return ++count;
}

// int main() {
//     printf("%d\n", mx_count_words("   follow   *   the  white rabbit  ", ' '));
//     return 0;
// }
