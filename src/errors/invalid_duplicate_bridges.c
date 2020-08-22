#include "pathfinder.h"

static void mx_islands_sort(char *one, char *two, int index_line, char *string) {
    int i = index_line;

    for (int j = 0; one[j] != '\0'; i++, j++)
        string[i] = one[j];
    string[i++] = '-';
    for (int j = 0; two[j] != '\0'; i++, j++)
        string[i] = two[j];
}

static void island_check_order(char *string) {
    int i = 0;
    int j = 0;
    char a[150];
    char b[150];
    int temp = 0;
    
    for (int z = 0; z < in_data.num_of_bridges; z++) {
        for (j = 0 ; string[i] != '-'; j++, i++)
            a[j] = string[i];
        a[j] = '\0';
        for (j = 0, i++; string[i] != ','; j++, i++)
            b[j] = string[i];
        b[j] = '\0';
        if (mx_strcmp(a, b) > 0) 
            mx_islands_sort(b, a, temp, string);      // sort islands in ascetic order in a line
        while (string[++i] != '\n') {};
        temp = ++i;
    }          
}

static char *mx_dup_from_two_line(char *src) {
    int i = 0;
    int len_src = mx_strlen(src);

    while (src[i] != '\n') 
        i++;
    i++; 
    char *dst = mx_strnew(len_src - i);
    for (int j = 0; j < len_src - i; j++)
        dst[j] = src[j + i];
    return dst;
}

void print_error(char *temp_str) {
    mx_printerr("error: duplicate bridges\n");
    free(in_data.string);
    free(in_data.uniqe_islands);
    free(temp_str);
    exit(1);
}

void inv_duplicate_bridges(void) {
    char *temp_str = mx_dup_from_two_line(in_data.string);
    int z = 0;
    int  index_line = 0;

    island_check_order(temp_str);
    for (int i = 0; temp_str[i] != '\0'; i++)
        if (temp_str[i] == ',')
            temp_str[i] = '\0';
    for (int i = 0; i < in_data.num_of_bridges - 1; i++) {
        for (int j = i; j < in_data.num_of_bridges - 1; j++) {
            for ( ; temp_str[z] != '\n'; z++) {};
            if ((mx_strcmp(&temp_str[index_line], &temp_str[++z])) == 0)
                print_error(temp_str);
        }
        while (temp_str[index_line++] != '\n') {};
        z = index_line;
    }  
    free(temp_str);
}
