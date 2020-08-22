#include "pathfinder.h"

static char *mx_strjoin_mod(char *str1, const char *s2) {
    char *str_join = NULL;
    int str1_len = 0;
    int s2_len = 0;

    if (!str1 && !s2) 
        return NULL;
    if (str1)
        str1_len = mx_strlen(str1);
    if (s2)
        s2_len = mx_strlen(s2);
    str_join = mx_strnew(str1_len + s2_len);
    if (str1)
        str_join = mx_strcpy(str_join, str1);
    if (s2) {
        str_join = mx_strcpy(&str_join[str1_len], s2);
        str_join -= str1_len;
    }
    free(str1);
    return str_join;
}

static char *islands_in_str(char *temp_island, char *temp_str) {
    int i = 0;
    int j = 0;
    int z = 0;

    temp_str[j++] = ' ';
    for ( ; in_data.string[i] != '\n'; i++);
    for (i++; in_data.string[i] != '-'; j++, i++)
        temp_str[j] = in_data.string[i];
    temp_str[j] = ' ';
    for ( ; in_data.string[i] != '\0'; i++) {
        if ((in_data.string[i] == '-' || in_data.string[i] == '\n') && in_data.string[i+1] != '\0') {
            temp_island[0] = ' ';
            for (z = 1, ++i; ((in_data.string[i] != '-') && (in_data.string[i] != ',')); z++, i++)
                temp_island[z] = in_data.string[i];
            temp_island[z] = ' ';
            temp_island[++z] = '\0';
            i--;
        }
        if (mx_count_substr(temp_str, temp_island) == 0) {
            temp_str = mx_strjoin_mod(temp_str, temp_island);
        }
    }
    temp_str[mx_strlen(temp_str) - 1] = '\0';
    return temp_str;
}

static bool compare_count(char *str) {
    int i = mx_count_words(str, ' ');
    if (i != in_data.num_of_islands) 
        return false;
    return true;
}

void inv_number_of_islands(void) {
    char *temp_str = mx_strnew(in_data.file_len + 1);
    char temp_island[150];

    temp_str = islands_in_str(temp_island, temp_str);
    temp_str = mx_del_extra_spaces(temp_str);
    if (!compare_count(temp_str)) {
        mx_printerr("error: invalid number of islands\n");
        free(in_data.string);
        free(temp_str);
        exit(1);
    }
    in_data.uniqe_islands = temp_str;
}
