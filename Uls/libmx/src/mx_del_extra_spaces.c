#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str) 
        return NULL;
    char *str_trim = mx_strtrim(str);
    int printable = mx_count_printable(str_trim);
    int words = mx_ws_count_words(str_trim);
    char *str_del = mx_strnew(printable + words - 1);
    int len = mx_strlen(str_trim);
    
    for (int i = 0, j = 0; i < len; i++) {
        if (!mx_isspace(str_trim[i])) {
            str_del[j] = str_trim[i];
            j++;
        } 
        else if (!mx_isspace(str_trim[i + 1])) {
            str_del[j++] = ' ';
        }
    }
    free((void*)str);
    free(str_trim);
    return str_del;
}

// int main() {
//     char name[] = "\f   My name...  is \r  Neo  \t   \n  ";
//     //char *name = NULL;
//     char *str_del = mx_del_extra_spaces(name);
//     printf("%s", str_del); 
//     free(str_del);
//     return 0;
// }
