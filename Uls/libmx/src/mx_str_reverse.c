#include "libmx.h"

void mx_str_reverse(char *s) {
    int left = 0;
    int right = 0; 
    char buff;

    if (s) {
        right = mx_strlen(s) - 1;
        while (left < right) {
            buff = s[left];
            s[left++] = s[right];
            s[right--] = buff;
        }
    }
}

// int main() {
//     char *str = "game over";
//     mx_str_reverse(str);
//     printf("%s\n", str);
//     return 0;
// }
