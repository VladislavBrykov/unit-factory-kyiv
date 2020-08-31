#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if(!str || !sub || !replace)
        return NULL;
    int count_sub = mx_count_substr(str, sub);
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);
    char *result = mx_strnew(sizeof(char) * (mx_strlen(str) - sub_len * count_sub + replace_len * count_sub));

    if(!result) 
        return NULL;
    for (int i = 0, j = 0; count_sub >= 0; i += sub_len, j += replace_len, count_sub--)
        if (count_sub > 0) {
            while (i < mx_get_substr_indexes(str, sub, i))
                result[j++] = str[i++];
            mx_str_pos_cpy(result, replace, j);
        } 
        else
            while (str[i])
                result[j++] = str[i++];
    return result;
}

// int main () {
//     char *result = mx_replace_substr("eto pizdec, ponlnyi pizdec", "pizdec", "pipec");
//     printf("%s\n", result); 
//     free(result);
//     return 0;
// }
