#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (!str) 
        return NULL;
    int left = 0;
    int right = mx_strlen(str) - 1;
    char *trim = NULL;

    while (1) {
        while (mx_isspace(str[left])) 
            left++;
        while (mx_isspace(str[right])) 
            right--;
        if (left > right) {
            return NULL;
        } 
        else
            break;
    }
    trim = mx_str_pos_dup((char*)str, left, right);
    return trim;
}

// int main() {
//     char name[] = "\f  My name... is Neo  \t\n ";
//     char *trim = mx_strtrim(name);
//     printf("%s\n", trim); 
//     free(trim);
//     return 0;
// }
