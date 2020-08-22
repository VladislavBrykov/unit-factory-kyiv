#include "pathfinder.h"

static int mx_number_str(char *str, int one_num) {
    int number = one_num;

    while (str[number] != '\n') {
        if (str[number + 2] == '\0' && number == one_num)
            return -2;
        if (str[number + 2] == '\0')
            return -1;
        number++;
    }
    return ++number;
}

static bool format_of_str(char *str, int one_num) {
    int i = one_num;
    int tmp = i;

    for ( ; str[i] != '-'; ++i)
        if (!mx_isletter(str[i]))
            return false;
    if (tmp  == i++)
        return false;
    tmp = i;
    for ( ; str[i] != ','; ++i)
        if (!mx_isletter(str[i]))
            return false;
    if (tmp  == i++)
        return false;
    tmp = i;
    if (str[i] == '0')
        return false;
    for ( ; str[i] != '\n'; ++i)
        if (!mx_isdigit(str[i]))
            return false;
    if (tmp  == i)
        return false;
    return true;
}

static bool island_check(char *str, int one_num) {
    int i = one_num;
    int j = 0;
    char a[150];
    char b[150];
    
    for ( ; str[i] != '-'; j++, i++)
        a[j] = str[i];
    a[j] = '\0';
    for (j = 0, i++; str[i] != ','; j++, i++)
        b[j] = str[i];
    b[j] = '\0';
    if (!mx_strcmp(a, b))
        return false;           
    return true;
}

void invalid_format_line(void) {
    int cur_number = 0;
    int line = 1;

    while (1) {
        cur_number = mx_number_str(in_data.string, cur_number);
        if (cur_number != -1) {
            line++;
            if (cur_number == - 2 || !format_of_str(in_data.string, cur_number) || !island_check(in_data.string, cur_number)) {
                char *line_str;
                mx_printerr("error: line ");
                mx_printerr(line_str = mx_itoa(line));
                mx_printerr(" is not valid\n");
                free(line_str);
                free(in_data.string);
                exit(1);
            }
        }
        else
            break;
    }
    in_data.num_of_bridges = line - 1;
}
